#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){

    int inbuf[2];
    int outbuf[2];
    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);
    int buf[2];

    if(world_rank==0){
        inbuf[0]=7;
        inbuf[1]=1;
    }
    
    else if(world_rank==1){
        inbuf[0]=3;
        inbuf[1]=2;
    }

    if(world_rank==2){
        inbuf[0]=5;
        inbuf[1]=2;
    }
    
    MPI_Reduce(inbuf,outbuf,2,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    if(world_rank==0){
        printf("Total sum is %d  %d",outbuf[0],outbuf[1]);
    }
    MPI_Finalize();
    return 0;
}    