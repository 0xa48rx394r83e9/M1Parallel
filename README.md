# M1Parallel

M1Parallel is a high-performance, parallel computing library designed specifically for Apple Silicon (M1) devices. It provides a set of APIs and tools to leverage the power of parallel computing paradigms, including shared memory parallelism, distributed memory parallelism, and task parallelism.

## Features

- Shared Memory Parallelism: Utilize multiple cores on a single device using pthreads for efficient parallel execution.
- Distributed Memory Parallelism: Harness the power of multiple devices using Message Passing Interface (MPI) for distributed computing.
- Task Parallelism: Easily express and execute parallel tasks using a simple and intuitive task-based programming model.
- Compatibility: Seamlessly integrate with existing parallel programming standards such as OpenMP and MPI.
- Optimized for Apple Silicon: Leveraging the unique capabilities of M1 devices to achieve optimal performance.

### File Structure

```
.
├── README.md
├── examples
│   ├── distributed_memory_example.c
│   ├── shared_memory_example.c
│   └── task_parallelism_example.c
├── include
│   └── parallel_lib
│       ├── distributed_memory
│       │   └── mpi_wrapper.h
│       ├── parallel_lib.h
│       ├── shared_memory
│       │   └── parallel_for.h
│       └── task_parallelism
│           └── task.h
└── src
    ├── distributed_memory
    │   └── mpi_wrapper.c
    ├── shared_memory
    │   └── parallel_for.c
    └── task_parallelism
        └── task.c
```

## Usage

Here's a simple example that demonstrates how to use M1Parallel for shared memory parallelism (more examples are provided in the examples folder):

```c
#include <stdio.h>
#include "parallel_lib/shared_memory/parallel_for.h"

void print_number(int num) {
    printf("Number: %d\n", num);
}

int main() {
    parallel_for(0, 10, print_number);
    return 0;
}
```
