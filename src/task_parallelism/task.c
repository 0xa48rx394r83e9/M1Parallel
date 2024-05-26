#include "task.h"
#include <stdlib.h>

task *create_task(task_func func, void *arg)
{
    task *t = (task *)malloc(sizeof(task));
    t->func = func;
    t->arg = arg;
    return t;
}

void execute_task(task *t)
{
    t->func(t->arg);
}

void destroy_task(task *t)
{
    free(t);
}