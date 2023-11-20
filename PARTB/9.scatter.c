#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){

    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);
    
    int data[world_size];
    int recv_data;

    if(world_rank==0){
        for(int i=0;i<world_size;i++){
            data[i]=i;
        }
    }

    MPI_Scatter(data,1,MPI_INT,&recv_data,1,MPI_INT,0,MPI_COMM_WORLD);

    printf("\n Process %d received data %d",world_rank,recv_data);

    MPI_Finalize();
    return 0;
}    
