#include <stdio.h>
#include "parallel_lib/distributed_memory/mpi_wrapper.h"

int main()
{
    mpi_init();

    int rank = mpi_rank();
    int size = mpi_size();

    if (rank == 0)
    {
        int data = 42;
        mpi_send(&data, 1, MPI_INT, 1, 0);
        printf("Sent data: %d\n", data);
    }
    else if (rank == 1)
    {
        int received_data;
        mpi_recv(&received_data, 1, MPI_INT, 0, 0);
        printf("Received data: %d\n", received_data);
    }

    mpi_finalize();
    return 0;
}