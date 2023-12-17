#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define Terms 1000000

void main(){
    double piS=0.0;
    double piP=0.0;
    int k=0;

    double start=omp_get_wtime();
    for(k=0;k<Terms;k++){
        double t=(k%2 == 0) ? 1.0 : -1.0;
        piS  += t/(2.0 * k + 1.0);
    }
    double end=omp_get_wtime();

    piS*=4.0;
    printf("\n Time for serial execution is %f",end-start);
    printf("PI serial value %6.12f ",piS);

    start=omp_get_wtime();
    #pragma omp parallel for reduction(+:piP)
    for(k=0;k<Terms;k++){
        double t=(k % 2 == 0) ? 1.0 : -1.0;
        piP += t/(2.0 * k + 1.0);
    }
    end=omp_get_wtime();

    piP*=4.0;
    printf("\n Time for parallel execution is %f",end-start);
    printf("PI parallel value %6.12f ",piP);
    
}
