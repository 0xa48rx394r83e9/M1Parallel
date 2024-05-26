#include "mpi_wrapper.h"

void mpi_init()
{
    MPI_Init(NULL, NULL);
}

void mpi_finalize()
{
    MPI_Finalize();
}

int mpi_rank()
{
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    return rank;
}

int mpi_size()
{
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    return size;
}

void mpi_send(void *data, int count, MPI_Datatype datatype, int dest, int tag)
{
    MPI_Send(data, count, datatype, dest, tag, MPI_COMM_WORLD);
}

void mpi_recv(void *data, int count, MPI_Datatype datatype, int source, int tag)
{
    MPI_Recv(data, count, datatype, source, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}