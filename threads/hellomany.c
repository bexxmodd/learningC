#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 16

void *print_hello(void *val)
{
    pthread_detach(pthread_self());
    printf("Hello from thread %lu - I was created in iteration %d\n", pthread_self(), (int) val);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        perror("Please provide number of threads you want to create");
        exit(1);
    }

    int n = atoi(argv[1]);
    pthread_t threads[MAX_THREADS];
    pthread_t tid = pthread_self();

    for (int i = 0; i < n; i++) {
        if (pthread_create(&threads[i], NULL, print_hello, (void *) i)) {
            perror("\n ERROR: return code is invalid");
            exit(1);
        }
    }

    for (int i = 0; i < n; i++)
        printf("I am thread %lu. Created new thread %lu in iteration %d\n", tid, threads[i], i);

    pthread_exit(NULL);
    return 0;
}