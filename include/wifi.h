#pragma once

#include "pico/cyw43_arch.h"
#include <string.h>
#include <stdlib.h>

#include "pico/stdlib.h"

#include "lwip/pbuf.h"
#include "lwip/tcp.h"

#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define TCP_PORT 80
#define DEBUG_printf printf
#define BUF_SIZE 2048
#define TEST_ITERATIONS 2
#define POLL_TIME_S 5

#define LED_PIN 0

extern char request_body[BUF_SIZE];

typedef struct TCP_SERVER_T_
{
    struct tcp_pcb *server_pcb;
    struct tcp_pcb *client_pcb;
    bool complete;
    uint8_t buffer_sent[BUF_SIZE];
    uint8_t buffer_recv[BUF_SIZE];
    int sent_len;
    int recv_len;
    int run_count;
} TCP_SERVER_T;

int wifi_setup();
void run_tcp_server_test(void);
static TCP_SERVER_T *tcp_server_init(void);
static bool tcp_server_open(void *arg);
static err_t tcp_server_result(void *arg, int status);
static err_t tcp_server_accept(void *arg, struct tcp_pcb *client_pcb, err_t err);
static err_t tcp_server_close(void *arg);
static err_t tcp_server_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
err_t tcp_server_send_data(void *arg, struct tcp_pcb *tpcb);
err_t tcp_server_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static err_t tcp_server_poll(void *arg, struct tcp_pcb *tpcb);
static void tcp_server_err(void *arg, err_t err);

void handle_post_request(char *response);
void handle_options_request(char *response);
