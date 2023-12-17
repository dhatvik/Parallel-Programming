#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void vector_add_parallel(int n,int a[],int b[],int res[]){
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp critical
        res[i]=a[i]+b[i];
    }
}

void main(){
    int n;
    printf("\n Enter the value of n");
    scanf("%d",&n);
    int a[n],b[n],res[n];

    for(int i=0;i<n;i++){
        a[i]=rand()%10;
        b[i]=rand()%10;
    }
    double start=omp_get_wtime();
    vector_add_parallel(n,a,b,res);
    double end =omp_get_wtime();
    for(int i=0;i<n;i++){
        printf("\n %d + %d is %d ",a[i],b[i],res[i]);
    }
    printf("\n Time for paralle vector addition is %f",end -start);
}
