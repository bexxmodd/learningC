#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1024
int a[N][N], b[N][N], c[N][N];

#define NCORES 8
int a[N][N], b[N][N], c[N][N];

void *thread_fn(void *data)
{
    int *p = (int *)data;
    int i, j, k;

    for (i = *p; i < (*p + (N / NCORES)); i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

    pthread_exit((void *)0);
}

int main()
{
    int i, j, row[NCORES];
    pthread_t tid[NCORES];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = 2;
            b[i][j] = 3;
        }
    }

    for (i = 0; i < NCORES; i++) {
        row[i] = i * (N / NCORES);
        pthread_create(&tid[i], NULL, thread_fn, &row[i]);
    }

    // wait until all other threads complete
    for (i = 0; i < NCORES; i++)
        pthread_join(tid[i], NULL);

#if 0
    printf("The resultant matrix is:\n");
	for (i = 0; i < N; i++) {
		printf(" [row %3d]  ", i+1);
		for (j = 0; j < N; j++)
			printf("%d ", c[i][j]);
		printf(" [row %3d]\n", i+1);
	}
#endif
    pthread_exit((void *)0);
}