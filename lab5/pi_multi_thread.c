#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h> 

#define NUM_THREADS 4 

int range;
int count[NUM_THREADS];
int sum = 0;

void *calPi(void *count)
{
    int *p;
    p = (int*) count;
    float x, y;
    unsigned int seed = rand();
    for (int i = 0; i < range; i++)
    {
        x = rand_r(&seed) / (float) RAND_MAX;
        y = rand_r(&seed) / (float) RAND_MAX;
        float results = sqrt(x * x + y * y);
        if (results <= 1)
            *p += 1;
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    
    gettimeofday(&start, NULL);

    range = atoi(argv[1]) / NUM_THREADS;
    
    pthread_t tid[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&tid[i], NULL, calPi, &count[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tid[i], NULL);
        sum += count[i];
    }
    
    float pi = 4 * (float) sum / range / NUM_THREADS;
    
    gettimeofday(&end, NULL);
    
    float t = ((end.tv_usec - start.tv_usec) * 0.000001 + end.tv_sec) - start.tv_sec;
        
    printf("The value of Pi is: %f\n", pi);
    printf("Time taken: %f \n", t);
    pthread_exit(NULL);
}

