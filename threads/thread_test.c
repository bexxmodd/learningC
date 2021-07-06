#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREADS 100000
    
void *do_nothing(void *data)
{
        unsigned long t = 0xb00da;
        pthread_exit(NULL);
}

int main()
{
        int ret, i;
        pthread_t tid;
        pthread_attr_t attr;

        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        for (i = 0; i < NTHREADS; i++) {
                ret = pthread_create(&tid, &attr, do_nothing, NULL);
                if (ret) exit(1);

                ret = pthread_join(tid, NULL);
                if (ret) exit(1);
        }

        pthread_attr_destroy(&attr);
        pthread_exit(NULL);
        return 0;
}
