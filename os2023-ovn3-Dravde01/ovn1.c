#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

int count = 0;
pthread_mutex_t mymutex;

void *print_hello(void *p)
{
	int tmp;
	intptr_t thread_n;
	thread_n = (intptr_t)p;
	printf("Hello! I'm thread #%ti\n", thread_n);
	pthread_mutex_lock(&mymutex);
	for (int i = 0; i < UPDATE_COUNT; i++) 
	{
    	tmp = count; 
    	count = tmp + 1;
	}
	pthread_mutex_unlock(&mymutex);
	return NULL;
}

int main()
{
	pthread_t thread_ids[N_PTHREADS];
	int ret;
	intptr_t i;

	if (pthread_mutex_init(&mymutex, NULL) != 0)
	{
		printf("Mutex init failed\n");
		return -1;
	}

	for (i = 0; i < N_PTHREADS; i++) {
		printf("Creating thread #%ti\n", i);
		ret = pthread_create(&thread_ids[i], NULL, print_hello, (void *)i);
		if (ret != 0) {
			printf("ERROR: pthread_create() returned %i\n", ret);
			return -1;
		}
	}

	for (i = 0; i < N_PTHREADS; i++) {
		pthread_join(thread_ids[i], NULL);
	}
	
	pthread_mutex_destroy(&mymutex);

	int real_count = UPDATE_COUNT*N_PTHREADS;
	float percentage = (float) count/real_count * 100;

	printf("count = %d, should be %d, %f%%\n", count, real_count, percentage);

	return 0;
}