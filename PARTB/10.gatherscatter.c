#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){

    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);

    int data[4]={11,12,13,14};
    int recv_data;
    int gathered_data[4];

    MPI_Scatter(data,1,MPI_INT,&recv_data,1,MPI_INT,0,MPI_COMM_WORLD);
    printf("\n Process %d recieved data %d",world_rank,recv_data);

    MPI_Barrier(MPI_COMM_WORLD);
    
    recv_data+=10;

    MPI_Gather(&recv_data,1,MPI_INT,gathered_data,1,MPI_INT,0,MPI_COMM_WORLD);
    if(world_rank==0){
        printf("\n Data gathered after adding 10 is \n");
        for(int i=0;i<world_size;i++){
            printf(" %d \t",gathered_data[i]);
        }
    }
    MPI_Finalize();
    return 0;
}    
