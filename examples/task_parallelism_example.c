#include <stdio.h>
#include "parallel_lib/task_parallelism/task.h"

void task_function(void *arg)
{
    int *value = (int *)arg;
    printf("Task executed with value: %d\n", *value);
}

int main()
{
    int value1 = 10;
    int value2 = 20;

    task *task1 = create_task(task_function, &value1);
    task *task2 = create_task(task_function, &value2);

    execute_task(task1);
    execute_task(task2);

    destroy_task(task1);
    destroy_task(task2);

    return 0;
}