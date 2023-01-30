#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("sleep: missing operand\n");
    }
    sleep(atoi(argv[1]) * 10);
    exit(0);
}
