import network
import socket
import asyncio
from time import sleep
import json

class PicoWWebReceiver:
    """
    Initialize the Pico W web receiver
    
    :param ssid: WiFi network name
    :param password: WiFi network password
    """
    def __init__(self, ssid, password):
        self.wlan = network.WLAN(network.STA_IF)
        self.ssid = ssid
        self.password = password
        
        self.init_wifi()
        
    def init_wifi(self):
        self.wlan.active(True)
        self.wlan.connect(self.ssid, self.password)
        
        max_wait = 10
        while max_wait > 0:
            if self.wlan.status() < 0 or self.wlan.status() >= 3:
                break
            max_wait -= 1
            print('waiting for connection...')
            sleep(1)
        
        if self.wlan.status() != 3:
            raise RuntimeError('network connection failed')
        else:
            status = self.wlan.ifconfig()
            print('ip = ' + status[0])
        
    async def handle_client(self, reader, writer):
        try:
            request_line = await reader.readline()
            request_method = str(request_line, 'utf-8').split()[0] if request_line else ''
                
            print(f"Received {request_method} request")

            cors_headers = (
                "HTTP/1.1 200 OK\r\n"
                "Access-Control-Allow-Origin: *\r\n"
                "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
                "Access-Control-Allow-Headers: Content-Type, Accept\r\n"
                "Access-Control-Max-Age: 3600\r\n"
            )

            # Handle OPTIONS preflight
            if request_method == 'OPTIONS':
                response = (
                    f"{cors_headers}"
                    "Content-Length: 0\r\n"
                    "\r\n"
                )
                writer.write(response.encode())
                await writer.drain()
                return

            if request_method == 'POST':
                content_length = 0
                while True:
                    header = await reader.readline()
                    if header == b'\r\n':
                        break
                    if header.lower().startswith(b'content-length:'):
                        content_length = int(header.decode().split(':')[1].strip())

                body = await reader.read(content_length)                
                parsed_data = json.loads(body.decode('utf-8'))
                print('Received data:', parsed_data)

                # Prepare response
                response_body = json.dumps({
                    'message': 'Pico W received location and compass readings successfully 🎉🎉'
                })

                response = (
                    f"{cors_headers}"
                    f"Content-Type: application/json\r\n"
                    f"Content-Length: {len(response_body)}\r\n"
                    "\r\n"
                    f"{response_body}"
                )

                writer.write(response.encode())
                await writer.drain()
        
        except Exception as e:
            print(f"Error handling client: {e}")
            # Send error response
            error_response = (
                f"{cors_headers}"
                "Content-Type: application/json\r\n"
                f"Content-Length: {len(str(e))}\r\n"
                "\r\n"
                f"{{'error': '{e}'}}"
            )
            writer.write(error_response.encode())

        finally:
            writer.close()
            await writer.wait_closed()


async def main():
    WIFI_SSID = ''
    WIFI_PASSWORD = ''
    
    receiver = PicoWWebReceiver(WIFI_SSID, WIFI_PASSWORD)

    server = asyncio.start_server(receiver.handle_client, "0.0.0.0", 80)
    asyncio.create_task(server)

loop = asyncio.get_event_loop()
loop.create_task(main())

try:
    loop.run_forever()
except Exception as e:
    print('Error occured: ', e)
except KeyboardInterrupt:
    print('Program Interrupted by the user')
