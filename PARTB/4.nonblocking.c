#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    
    int world_rank,world_size;
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);

    if(world_size<2){
        printf("Number of processors should be atleast 2");
        MPI_Finalize();
        return 0;
    }
    int number=7;
    MPI_Request req;
    MPI_Status sta;
    if(world_rank==0){
        MPI_Isend(&number,1,MPI_INT,1,0,MPI_COMM_WORLD,&req);
        MPI_Irecv(&number,1,MPI_INT,1,0,MPI_COMM_WORLD,&req);
        MPI_Wait(&req,&sta);
        printf("\n process 0 recieved number %d from process 1 ",number);
    }
    else if(world_rank==1){
        MPI_Irecv(&number,1,MPI_INT,0,0,MPI_COMM_WORLD,&req);
        MPI_Wait(&req,&sta);
        MPI_Isend(&number,1,MPI_INT,0,0,MPI_COMM_WORLD,&req);
        MPI_Wait(&req,&sta);
        printf("\n process 1 sent number %d to process 0 ",number);
    }

    MPI_Finalize();
    return 0;

}
