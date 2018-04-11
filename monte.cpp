#include <stdio.h>

#include <pthread.h>
#include <stdlib.h>

#include <time.h>
long long point_thread;
long long circle_points = 0;

pthread_mutex_t l;

void *fun() {

	pthread_mutex_lock(&l);

	long circle_points_thread = 0;
		  srand((unsigned)time(NULL));

	unsigned int rand_state = rand();

        int i;
   	for (i = 0; i < point_thread; i++) {

        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            circle_points_thread++;
        }
    }
    
    circle_points += circle_points_thread;
    pthread_mutex_unlock(&l);
}

int main(int argc, const char *argv[])
{

 int i;
 pthread_mutex_init(&l,NULL);
    long totalpoints = atol(argv[1]);
    int thread_count = atoi(argv[2]);
    point_thread = totalpoints / thread_count;


    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));
   
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, fun, (void *) NULL);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&l);

    printf("Estimated value of pi is %f\n", (4* (double)circle_points) / ((double)point_thread * thread_count));

    return 0;
}
