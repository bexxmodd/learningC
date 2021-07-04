#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    switch (pid = fork()) {
        case -1:
            perror("fork failed");
            break;
        case 0:
            printf("I'm child process and I will execute ls command");
            char * argv_list[] = {"ls", "-al", "/home", NULL};
            execv("ls", argv_list);
            break;
        default:
            printf("I'm parent process and I'll just print this");
        }
        
    return 0;
}