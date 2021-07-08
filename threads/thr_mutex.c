#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 3
#define MYCONST 3

static int locking = 1;
static long g1=10, g2=12, g3=13;
static pthread_mutex_t mylock;

static void *worker(void *data)
{
    long datum = (long)data + 1;
    int ret = 0;

    if (locking)
        if ((ret = pthread_mutex_lock(&mylock)))
            exit(EXIT_FAILURE);

    /* ---- Critical Section Begins---- */
    g1++; g2++; g3++;
    printf("[Thread #%ld] %2ld   %2ld   %2ld\n", datum, g1, g2, g3);
    /* ---- Critical Section Ends ---- */

    if (locking)
        if ((ret = pthread_mutex_unlock(&mylock)))
            exit(EXIT_FAILURE);
    
    // terminate with success and join will pick this up
    pthread_exit((void *)0);
}

static inline void usage(char *name)
{
    fprintf(stderr, "Usage: %s lock-or-not\n"
			" 0 : do Not lock (buggy!)\n"
			" 1 : do lock (correct)\n", name);
}

int main(int argc, char **argv)
{
	long i;
	int ret, stat=0;
	pthread_t tid[NTHREADS];

	if (argc != 2) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	if (atoi(argv[1]) == 0)
		locking = 0;
	else if (atoi(argv[1]) == 1)
		locking = 1;
	else {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

    if (locking)
        if ((ret = pthread_mutex_init(&mylock, NULL)))
            exit(EXIT_FAILURE);
    
    printf("At start:   g1   g2   g3\n"
    "            %2ld   %2ld   %2ld\n", g1, g2, g3);

    // create threads
    for (i = 0; i < NTHREADS; i++) {
        ret = pthread_create(&tid[i], NULL, worker, (void *)i);
        if (ret)
            exit(EXIT_FAILURE);
    }

    // join threads
    for (i = 0; i < NTHREADS; i++) {
        ret = pthread_join(tid[i], (void **)&stat);
        if (ret)
            exit(EXIT_FAILURE);
    }
    if (locking)
        if ((ret = pthread_mutex_destroy(&mylock)))
            exit(EXIT_FAILURE);

    pthread_exit(NULL);
}