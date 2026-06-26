#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#include "receive.h"
#include "protocol.h"
#include "utils.h"

#define LISTEN_BACKLOG 50

/* TODO: configure it outside the source */
#define PORTNUM 1234

uint8_t g_last_data[MAX_DATA_SIZE] = {0};
size_t g_last_size = 0;
uint64_t g_last_time = 0;

int g_socket = -1;

int receive_init()
{
    g_socket = socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);
    if (g_socket < 0)
    {
        perror("");
        return 1;
    }
    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = htons(PORTNUM), .sin_addr = INADDR_ANY};
    bind(g_socket, (struct sockaddr *)&addr, sizeof(addr));
    LOG_DEBUG("receive module initialized\n");
    return 0;
}

int receive_iterate()
{
    packet_t packet = {0};

    struct sockaddr src_addr;
    socklen_t addrlen;

    size_t bytes = recvfrom(g_socket, &packet, sizeof(packet), 0, &src_addr, &addrlen);
    if (bytes == -1)
    {
        return 1;
    }
    checksum_t checksum = calculate_checksum((void *)packet.data, packet.data_size);
    LOG_DEBUG("calculated checksum of received packet: %d\n", checksum);
    if (checksum != packet.data_checksum)
    {
        LOG_DEBUG("checksums do not match, ignoring packet\n");
        return 1;
    }
    LOG_DEBUG("updating global data buffer\n");
    memset(g_last_data, 0, MAX_DATA_SIZE);
    memcpy(g_last_data, packet.data, packet.data_size);
    g_last_size = packet.data_size;
    g_last_time = get_absolute_nanoseconds();
    LOG_DEBUG("g_last_data is \"%s\"\n", g_last_data);
    return 0;
}

int receive_destroy()
{
    close(g_socket);
    LOG_DEBUG("destroy socket module\n");
    return 0;
}