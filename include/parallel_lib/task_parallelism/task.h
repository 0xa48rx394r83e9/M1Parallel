#ifndef TASK_H
#define TASK_H

typedef void (*task_func)(void *);

typedef struct
{
    task_func func;
    void *arg;
} task;

task *create_task(task_func func, void *arg);
void execute_task(task *t);
void destroy_task(task *t);

#endif