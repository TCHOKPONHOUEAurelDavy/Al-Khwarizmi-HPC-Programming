#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int max_stride= 20;
    
    int N = 1000000;

    double *Tab;

    Tab = malloc(N*max_stride*sizeof(double));
    int i, k, i_stride;
    
    double MEAN, begin, end,RATE;


    for(k=0;k< N*max_stride;k++){
        Tab[k] =0;
    }

    

    for(i_stride = 1; i_stride <= max_stride; i_stride++){
        MEAN = 0.0;

        begin = (double)clock() / (double) CLOCKS_PER_SEC;

        for(i =0 ; i < N*i_stride; i = i +i_stride){
           
            MEAN = MEAN + Tab[i];

        }
        

        end = (double)clock() / (double) CLOCKS_PER_SEC;
        MEAN = MEAN / N;
 
         double mils = (end -  begin) * 1000.0 ;

         RATE = (sizeof(double)* N * (1000.0 / mils) )/ (1024*1024);

         printf("%d , %f, %f, %f \n",i_stride,MEAN,mils,RATE);
    }
}
