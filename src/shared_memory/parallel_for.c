#include "parallel_for.h"
#include <pthread.h>

typedef struct
{
    int start;
    int end;
    void (*func)(int);
} parallel_for_args;

void *parallel_for_thread(void *arg)
{
    parallel_for_args *args = (parallel_for_args *)arg;
    for (int i = args->start; i < args->end; i++)
    {
        args->func(i);
    }
    return NULL;
}

void parallel_for(int start, int end, void (*func)(int))
{
    int num_threads = 4; // Set the number of threads based on available cores
    pthread_t threads[num_threads];
    parallel_for_args args[num_threads];
    int chunk_size = (end - start) / num_threads;

    for (int i = 0; i < num_threads; i++)
    {
        args[i].start = start + i * chunk_size;
        args[i].end = (i == num_threads - 1) ? end : args[i].start + chunk_size;
        args[i].func = func;
        pthread_create(&threads[i], NULL, parallel_for_thread, &args[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
}