#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

float randNum()
{
    int random_value = rand();
    float random = random_value / (float) RAND_MAX;
    return random;
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    float num_in = 0;
    float total_num = 0;
    int iter = atoi(argv[1]);
    for (int i = 0; i < iter; i++)
    {
        float a = randNum();
        float b = randNum();
        float s = (a * a) + (b * b);
        float result = sqrt(s);
        if (result < 1)
            num_in += 1;
        total_num += 1;
    }

    float pi = 4 * num_in / total_num;
    
    gettimeofday(&end, NULL);
    float t = ((end.tv_usec - start.tv_usec) * 0.000001 + end.tv_sec) - start.tv_sec;

    
    printf("The value of Pi is: %f\n", pi);
    
    printf("Time taken: %f\n", t);
    return 0;
}
