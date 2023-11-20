#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    
    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);

    printf("Phase 1 :process %d of %d\n",world_rank,world_size);
    fflush(stdout);
    MPI_Barrier(MPI_COMM_WORLD);

    printf("Phase 2 : process %d of %d\n",world_rank,world_size);
    MPI_Finalize();
    return 0;
}    