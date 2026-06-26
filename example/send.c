#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#include "../common/protocol.h"

#define MSG "Hello World"

int main()
{
    packet_t packet;
    packet.data_size = 0xc;
    packet.data_checksum = 0x20;
    strcpy(packet.data, MSG);

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    sendto(udp_socket, &packet, sizeof(packet), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    puts("sent \"" MSG "\" to 127.0.0.1:1234");

    return 0;
}