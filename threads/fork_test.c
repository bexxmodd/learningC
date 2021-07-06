#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NFORKS 100000 

void do_nothing()
{
        unsigned long f = 0xb00da;
}

int main()
{
        int pid, j, status;

        for (j = 0; j < NFORKS; j++) {
                switch (pid = fork()) {
                        case -1:
                                perror("Fork failed!");
                                exit(1);
                        case 0:
                                do_nothing();
                                exit(EXIT_SUCCESS);
                        default:
                                waitpid(pid, &status, 0);
                }
        }
        return 0;
}
