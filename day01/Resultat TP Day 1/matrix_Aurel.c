#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main(){

    //initialisation des matrices 
    int i, j, k,ii,jj,kk,B,l, N = 1000;
    double *X, *Y,*Z;
    double start, end, bandw ;

    X = malloc(sizeof(double) * N);
    Y = malloc(sizeof(double) * N);
    Z = malloc(sizeof(double) * N);

    int block_table[] = {2,5,10,20,40};

    for(i = 0; i < N ; i++){
        for(j=0; j < N; j++){
            X[i,j] = 1.0;
            Y[i,j] = 1.0;
            Z[i,j] = 0.0;
        }
    }

    //multiplication par block


    for(l=0; l < sizeof(block_table)/sizeof(int); l++){

        B = block_table[l];

        

        start = (double)clock() / (double) CLOCKS_PER_SEC;
    
        for (ii = 0; ii < N; ii+=B) {
            for (jj = 0; jj < N; jj+=B) {
                for (kk = 0; kk < N; kk+=B) {

                    for (i = ii; i < ii+B; i++) {
                        for (j = jj; j < jj+B; j++) {
                            for (k = kk; k < kk+B; k++) {
                                Z[i,j] = Z[i,j] + (X[i,k]*Y[k,j]); //3 read + 1 write
                            }
                        }
                    }

                }
            }
        }

        end = (double)clock() / (double) CLOCKS_PER_SEC;

        double mils = (end -  start) * 1000.0 ;

        // les 4 operations se font B^3 * (N/B) ^ 3 fois

        bandw = ( sizeof(double)*  pow((N/B),3) * pow(B,3)  * 4 /(1024*1024) ) / (mils/1000.0) ;

        printf("%d,%f, %f \n",B,mils,bandw);
    
    }
}
