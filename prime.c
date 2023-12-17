#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n){
    if(n==0 || n==1){
        return 0;
    }
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void main(){
    int l=1;
    int n=50;

    double start=omp_get_wtime();
    #pragma omp parallel for 
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            int t=omp_get_thread_num();
            printf("\n thread %d prime number  %d",t,i);
        }
    }
    double end=omp_get_wtime();
    printf("Time for parallel execution is %f ",end-start);

    start=omp_get_wtime();
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            int t=omp_get_thread_num();
            printf("\n thread %d prime number is %d ",t,i);
        }
    }
    end=omp_get_wtime();
    printf("Time for serial execution is %f ",end-start);
}
