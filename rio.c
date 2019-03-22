#include "rio.h"
#include "errno.h"

ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
    ssize_t nleft = n;
    ssize_t nread = 0;
    char *bufp = usrbuf;

    // Read until nleft == 0, or until `read` return 0 (EOF) or error (< 0)
    while(nleft > 0){
        if((nread = read(fd, bufp, nleft)) < 0){
            if(nread == EINTR){
                nread = 0;
            }else{
                return -1;
            }
        }else if(nread == 0){
            break;
        }
        nleft -= nread;
        bufp += nread;
    }
    return n - nleft;
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
    ssize_t nleft = n;
    ssize_t nwrite = 0;
    char *bufp = usrbuf;

    // Write until nleft == 0, or until `write` return 0 (EOF) or error (< 0)
    while (nleft > 0) {
        if ((nwrite = write(fd, bufp, nleft)) <= 0) {
            if (nwrite == EINTR) {
                nwrite = 0;
            } else {
                return -1;
            }
        }
        nleft -= nwrite;
        bufp += nwrite;
    }
    return n ;
}