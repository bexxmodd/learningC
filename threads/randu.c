#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

/* create thread argument for thr_func() */
typedef struct _thread_data
{
    long long tid;
    long stuff;
} thread_data_t;

/* thread function */
void *thr_func(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    printf("Hello from thr_func, thread id: %lld\n", data->tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thr[NUM_THREADS];
    int i, rc;

    // create a thread data t argument array
    thread_data_t thr_data[NUM_THREADS];
    
    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thr[i], NULL, thr_func, &thr_data[i]);
        thr_data[i].tid = thr[i];
    }

    // block until all threads complete
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(thr[i], NULL);

    return 0;
}