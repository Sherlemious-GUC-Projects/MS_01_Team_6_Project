import React, { useState, useEffect } from "react";
import { MapPin, Car, Navigation, Play, Compass } from "lucide-react";
import Map from "./components/Map";
import axios from "axios";
import { toast } from 'react-toastify';

interface ILocation {
  lat: number;
  lng: number;
  name?: string;
  timestamp?: Date;
}

const App: React.FC = () => {
  const picoIpAddress = "http://192.168.129.90:80";
  const [carLocation, setCarLocation] = useState<ILocation | null>(null);
  const [destinationLocation, setDestinationLocation] =
    useState<ILocation | null>(null);
  const [isMoving, setIsMoving] = useState(false);
  const [compassHeading, setCompassHeading] = useState<number | null>(null);
  const [isDarkMode, setIsDarkMode] = useState(true);

  const sendCoordinatesToPico = async (location: ILocation) => {
    try {
      const payload = {
        car: {
          latitude: carLocation?.lat,
          longitude: carLocation?.lng,
        },
        destination: {
          latitude: location.lat,
          longitude: location.lng,
        },
        heading: compassHeading,
      };

      const response = await axios.post(
        picoIpAddress,
        JSON.stringify(payload),
        {
          headers: {
            "Content-Type": "application/json",
            Accept: "application/json",
          },
        },
      );

      if (response.status === 200) {
        console.log(response.data);
        toast.success(`Coordinates sent successfully: ${JSON.stringify(response.data)}`, {
          position: "bottom-right",
          autoClose: 3000,
        });
      }
    } catch (error) {
      console.error("Error sending coordinates to Pico W:", error);
      toast.error("Could not send location to the car", {
        position: "bottom-right",
        autoClose: 3000,
      });
    }
  };

  const handleDestinationChange = (
    carLocation: ILocation,
    destination: ILocation,
  ) => {
    setCarLocation(carLocation);
    setDestinationLocation(destination);
    setIsMoving(false);
  };

  const handleStartMoving = () => {
    if (!destinationLocation) {
      toast.warn("Please select a destination first!", {
        position: "bottom-right",
        autoClose: 3000,
      });
      return;
    }

    setIsMoving(true);
    sendCoordinatesToPico(destinationLocation);
    console.log("Starting movement to:", destinationLocation);
    toast.info(`Starting movement to: ${JSON.stringify(destinationLocation)}`, {
      position: "bottom-right",
      autoClose: 3000,
    });
  };

  const handleOrientation = (event: DeviceOrientationEvent) => {
    if (event.alpha !== null) {
      setCompassHeading(event.alpha);
    }
  };

  const requestCompassAccess = async () => {
    if (
      typeof (DeviceOrientationEvent as any).requestPermission === "function"
    ) {
      try {
        const permission = await (
          DeviceOrientationEvent as any
        ).requestPermission();
        if (permission === "granted") {
          window.addEventListener("deviceorientation", handleOrientation);
          console.log("")
          toast.success("Compass access granted!", {
            position: "bottom-right",
            autoClose: 3000,
          });
        } else {
          toast.error("Permission to access compass was denied.", {
            position: "bottom-right",
            autoClose: 3000,
          });
        }
      } catch (error) {
        console.error("Error accessing compass:", error);
        toast.error("Error accessing compass", {
          position: "bottom-right",
          autoClose: 3000,
        });
      }
    } else {
      window.addEventListener("deviceorientation", handleOrientation);
    }
  };

  useEffect(() => {
    return () => {
      window.removeEventListener("deviceorientation", handleOrientation);
    };
  }, []);

  return (
    <div
      className={`
      min-h-screen 
      ${isDarkMode
          ? "bg-gradient-to-br from-gray-900 to-gray-800 text-gray-100"
          : "bg-gradient-to-br from-blue-50 to-blue-100 text-gray-900"
        } 
      flex flex-col transition-colors duration-300 ease-in-out
    `}
    >
      <header
        className={`
        ${isDarkMode
            ? "bg-gray-800 shadow-2xl border-b border-gray-700"
            : "bg-white shadow-md"
          } 
        p-4 flex items-center justify-between transition-colors duration-300
      `}
      >
        <div className="flex items-center space-x-3">
          <Car
            className={`${isDarkMode ? "text-cyan-400" : "text-blue-600"}`}
            size={32}
          />
          <h1
            className={`text-2xl font-bold ${isDarkMode ? "text-gray-100" : "text-gray-800"}`}
          >
            Smart Car Tracker
          </h1>
        </div>

        <div className="flex items-center space-x-2">
          {carLocation && (
            <div
              className={`
              flex items-center space-x-1 
              ${isDarkMode ? "bg-green-900 text-green-300" : "bg-green-100 text-green-800"}
              px-3 py-1 rounded-full
            `}
            >
              <MapPin
                size={16}
                className={isDarkMode ? "text-green-400" : "text-green-600"}
              />
              <span className="text-sm">Connected</span>
            </div>
          )}

          <button
            onClick={() => setIsDarkMode(!isDarkMode)}
            className={`
              p-2 rounded-full transition-all duration-300 
              ${isDarkMode
                ? "bg-gray-700 hover:bg-gray-600 text-yellow-400"
                : "bg-gray-200 hover:bg-gray-300 text-blue-600"
              }
            `}
          >
            {isDarkMode ? "☀️" : "🌙"}
          </button>
        </div>
      </header>

      <main className="flex-grow flex flex-col lg:flex-row p-4 space-y-4 lg:space-y-0 lg:space-x-4">
        <div
          className={`
          lg:w-2/3 h-[500px] rounded-xl shadow-2xl overflow-hidden
          ${isDarkMode ? "bg-gray-800 border border-gray-700" : "bg-white"}
          transition-colors duration-300
        `}
        >
          <Map
            className="w-full h-full"
            defaultMark={carLocation || undefined}
            onChange={handleDestinationChange}
            defaultCenter={carLocation || undefined}
          />
        </div>

        <div className="lg:w-1/3 space-y-4">
          {carLocation && (
            <div
              className={`
              rounded-xl shadow-md p-4 space-y-2
              ${isDarkMode ? "bg-gray-800 border border-gray-700" : "bg-white"}
              transition-colors duration-300
            `}
            >
              <h2
                className={`
                text-xl font-semibold flex items-center
                ${isDarkMode ? "text-cyan-400" : "text-blue-600"}
              `}
              >
                <Navigation className="mr-2" size={24} />
                Current Location Details
              </h2>
              <p>
                <strong>Latitude:</strong> {carLocation.lat.toFixed(4)}
              </p>
              <p>
                <strong>Longitude:</strong> {carLocation.lng.toFixed(4)}
              </p>
            </div>
          )}

          {destinationLocation && (
            <div
              className={`
              rounded-xl shadow-md p-4 space-y-2
              ${isDarkMode ? "bg-gray-800 border border-gray-700" : "bg-white"}
              transition-colors duration-300
            `}
            >
              <h2
                className={`
                text-xl font-semibold flex items-center
                ${isDarkMode ? "text-cyan-400" : "text-blue-600"}
              `}
              >
                <Navigation className="mr-2" size={24} />
                Destination Details
              </h2>
              <p>
                <strong>Latitude:</strong> {destinationLocation.lat.toFixed(4)}
              </p>
              <p>
                <strong>Longitude:</strong> {destinationLocation.lng.toFixed(4)}
              </p>
              <p>
                <strong>Location:</strong> {destinationLocation.name}
              </p>
            </div>
          )}

          <div
            className={`
            rounded-xl shadow-md p-4 space-y-2
            ${isDarkMode ? "bg-gray-800 border border-gray-700" : "bg-white"}
            transition-colors duration-300
          `}
          >
            <h2
              className={`
              text-xl font-semibold flex items-center
              ${isDarkMode ? "text-cyan-400" : "text-blue-600"}
            `}
            >
              <Compass className="mr-2" size={24} />
              Compass Heading
            </h2>
            {compassHeading !== null ? (
              <p>
                <strong>Heading:</strong> {compassHeading.toFixed(2)}°
              </p>
            ) : (
              <button
                onClick={requestCompassAccess}
                className={`
                  w-full py-2 px-4 rounded transition-all duration-300
                  ${isDarkMode
                    ? "bg-cyan-800 text-cyan-200 hover:bg-cyan-700"
                    : "bg-blue-600 text-white hover:bg-blue-700"
                  }
                `}
              >
                Enable Compass
              </button>
            )}
          </div>

          <button
            onClick={handleStartMoving}
            disabled={!destinationLocation || isMoving}
            className={`
              w-full py-3 rounded-xl font-bold flex items-center justify-center space-x-2 transition-all duration-300
              ${destinationLocation && !isMoving
                ? isDarkMode
                  ? "bg-cyan-800 text-cyan-200 hover:bg-cyan-700 active:scale-95"
                  : "bg-blue-600 text-white hover:bg-blue-700 active:scale-95"
                : "bg-gray-600 cursor-not-allowed text-gray-400"
              }
            `}
          >
            <Play size={24} />
            <span>{isMoving ? "Moving..." : "Start Moving"}</span>
          </button>
        </div>
      </main>

      <footer
        className={`
        ${isDarkMode
            ? "bg-gray-800 text-gray-400 border-t border-gray-700"
            : "bg-white text-gray-600 shadow-md"
          }
        p-4 text-center transition-colors duration-300
      `}
      >
        © 2024 Smart Car Tracking System By Team #06
      </footer>
    </div>
  );
};

export default App;
