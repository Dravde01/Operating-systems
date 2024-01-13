#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MAX_LENGTH 100
double avg;
int min, max;

void *calcMaximum(void *param)
{
    int *arr = (int *)param;
    int elements = arr[0];
    int *buffer = &arr[1];
    max = INT_MIN;

    for (int i = 0; i < elements; i++) {
        if (buffer[i] > max) {
            max = buffer[i];
        }
    }

    pthread_exit(NULL);
}

void *calcMinimum(void *param)
{
    int *arr = (int *)param;
    int elements = arr[0];
    int *buffer = &arr[1];
    min = INT_MAX;

    for (int i = 0; i < elements; i++) {
        if (buffer[i] < min) {
            min = buffer[i];
        }
    }

    pthread_exit(NULL);
}

void *calcAverage(void *param)
{
    int *arr = (int *)param;
    int elements = arr[0];
    int *buffer = &arr[1];
    avg = 0.0;

    for (int i = 0; i < elements; i++) {
        avg += buffer[i];
    }
    avg = avg / elements;

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thread_ids[3];
    int buffer[MAX_LENGTH];
    int elements = argc - 1;
    
    if (argc > 1 && argc <= MAX_LENGTH + 1)
    {
        buffer[0] = elements;

        for (int i = 0; i < elements; i++) {
            buffer[i + 1] = atoi(argv[i + 1]);
        }

        int cAvg = pthread_create(&thread_ids[0], NULL, calcAverage, (void *)buffer);
        int cMin = pthread_create(&thread_ids[1], NULL, calcMinimum, (void *)buffer);
	    int cMax = pthread_create(&thread_ids[2], NULL, calcMaximum, (void *)buffer);
	    if (cAvg != 0 || cMin != 0 || cMax != 0) {
		    printf("ERROR: pthread_create() failed.\n");
		    return -1;
        }

        for (int i = 0; i < 3; i++) {
            pthread_join(thread_ids[i], NULL);
        }
    }
    else
    {
        return 1;
    }

    printf("The average value is %f\n", avg);
    printf("The minimum value is %d\n", min);
    printf("The maximum value is %d\n", max);

    return 0;
}