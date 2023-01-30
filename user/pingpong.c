#include "kernel/types.h"
#include "user/user.h"

void main()
{
    int p2c[2], c2p[2], number;
    pipe(p2c);  pipe(c2p);
    number = 0;
    if (fork() == 0) {
        read(p2c[0], &number, sizeof(int));
        printf("%d: received ping\n", getpid());
        write(c2p[1], &number, sizeof(int));
        close(p2c[0]);  close(p2c[1]);
        close(c2p[0]);  close(c2p[1]);
        exit(0);
    } else {
        write(p2c[1], &number, sizeof(int));
        printf("%d: received pong\n", getpid());
        read(c2p[0], &number, sizeof(int));
        close(p2c[0]);  close(p2c[1]);
        close(c2p[0]);  close(c2p[1]);
        exit(0);
    }
}