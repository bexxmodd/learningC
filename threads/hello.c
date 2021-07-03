#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *print_hello(void *data)
{
    pthread_t my_tid = (pthread_t) data;

    pthread_join(my_tid, NULL);
    // sleep(1);
    printf("Hello From New Thread -> %lu got -> %lu\n", pthread_self(), data);
    pthread_exit(NULL);
}

int main()
{
    int rc;
    long long tid;
    pthread_t thread_id;

    tid = pthread_self();

    rc = pthread_create(&thread_id, NULL, &print_hello, (void *)tid);
    if (rc )
    {
        perror("Error");
        exit(1);
    }
    sleep(1);
    printf("\n Created new thread (%lu) ... \n", thread_id);

    /* if we don't use pthread_exit at the end of the main program,
    when program exists all running threads will be killed */
    pthread_exit(NULL);
    return 0;
}