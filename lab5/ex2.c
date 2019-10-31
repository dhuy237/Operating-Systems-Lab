#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h> 

#define NUM_THREADS 4 

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long count = 0;
long range = 0;

void *calPi(void *arg)
{
    long count_temp = 0;
    float x, y;
    unsigned int seed = rand();
    for (int i = 0; i < range; i++)
    {
        x = rand_r(&seed) / (float) RAND_MAX;
        y = rand_r(&seed) / (float) RAND_MAX;
        float results = sqrt(x * x + y * y);
        if (results <= 1)
            count_temp += 1;
    }
    pthread_mutex_lock(&mutex);
    count += count_temp;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    
    gettimeofday(&start, NULL);

    range = atoi(argv[1]) / NUM_THREADS;
    
    pthread_t tid[NUM_THREADS];
    
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, calPi, (void*));
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
    }
    
    float pi = 4 * (float) count / (range * NUM_THREADS);
    
    gettimeofday(&end, NULL);
    //pthread_mutex_destroy(&mutex);
    float t = ((end.tv_usec - start.tv_usec) * 0.000001 + end.tv_sec) - start.tv_sec;
        
    printf("The value of Pi is: %f\n", pi);
    printf("Time taken: %f \n", t);
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}

