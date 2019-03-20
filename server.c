#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char **argv) {
    char host[128] = {0};
    struct ifreq ifr;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    /* IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;
    /* attatch IP address to "etho" */
    strncpy(ifr.ifr_name, "etho", IFNAMSIZ -1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.if_addr)->sin_addr));
    return 0;
}
