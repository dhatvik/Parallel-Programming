#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    
    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);

    if(world_size<2){
        printf("\nnumber of processors should be atleast 2");
        MPI_Finalize();
        return 0;
    }
    int number =777;
    if(world_rank==0){
        MPI_Send(&number,1,MPI_INT,1,0,MPI_COMM_WORLD);
        printf("\nProcess 0 is sent number %d to process 1",number);
    }
    else{
        MPI_Recv(&number,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("\nProcess 1 recieved number %d from process 0",number);
    }
    MPI_Finalize();
    return 0;
}