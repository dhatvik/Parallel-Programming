#include"mpi.h"
#include<stdio.h>

int main(int argc,char **argv)
{
    int rank;
    int buff[5];
    const int root =1;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank==root)
    {
        buff[0] = 111;
        buff[1] = 777;
    }
    printf("%d : before broadcast : buf[0] is %d\n",rank,buff[0]);
    printf("%d : before broadcast : buf[1] is %d\n",rank,buff[1]);

    MPI_Bcast(buff,2,MPI_AINT,root,MPI_COMM_WORLD);
    
    printf("%d : after broadcast , buff[0] is : %d\n",rank,buff[0]);
    printf("%d : after broadcast , buff[1] is : %d\n",rank,buff[1]);

    MPI_Finalize();
    return 0;
}