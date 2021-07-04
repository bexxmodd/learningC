#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void bond();

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int oxygen = 0;
int hydrogen = 0;

pthread_barrier_t barrier;

sem_t oxyQueue;
sem_t hydroQueue;

int bonds = 0;

void *oxygenCode()
{
    pthread_mutex_lock(&mutex);
    oxygen++;
    if (hydrogen >= 2)
    {
        sem_post(&hydroQueue);
        sem_post(&hydroQueue);
        hydrogen -= 2;
        sem_post(&oxyQueue);
        oxygen--;
    } else pthread_mutex_unlock(&mutex);

    sem_wait(&oxyQueue);
    bond();
    pthread_barrier_wait(&barrier);
    pthread_mutex_unlock(&mutex);
}

void *hydrogenCode()
{
    pthread_mutex_lock(&mutex);
    hydrogen++;
    if (hydrogen >= 2 && oxygen >= 1) {
        sem_post(&hydroQueue);
        sem_post(&hydroQueue);
        hydrogen -= 2;
        sem_post(&oxyQueue);
        oxygen--;
    } else pthread_mutex_unlock(&mutex);

    sem_wait(&hydroQueue);
    pthread_barrier_wait(&barrier);
}

void bond()
{
    printf("A H20 molecule is formed\n");
    bonds++;
}

int main()
{
    // pthread_mutex_init(&mutex, NULL);
    sem_init(&oxyQueue, 0, 0);
    sem_init(&hydroQueue, 0, 0);
    pthread_barrier_init(&barrier, NULL, 3);

    int rounds = 100;
    int n = 30;
    pthread_t bonds_thr[n];
    for (int i = 0; i < rounds; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 3 == 0)
                pthread_create(&bonds_thr[j], NULL, oxygenCode, NULL);
            else
                pthread_create(&bonds_thr[j], NULL, hydrogenCode, NULL);
        }
        for (int j = 0; j < n; j++)
            pthread_join(bonds_thr[j], NULL);
        
        printf("%d H20\n", bonds);
    }
}