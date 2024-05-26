#ifndef MPI_WRAPPER_H
#define MPI_WRAPPER_H

#include <mpi.h>

void mpi_init();
void mpi_finalize();
int mpi_rank();
int mpi_size();
void mpi_send(void *data, int count, MPI_Datatype datatype, int dest, int tag);
void mpi_recv(void *data, int count, MPI_Datatype datatype, int source, int tag);

#endif