#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct{
    int* arr;
    int threadnum;
}data;
void* findsum4threads(void * p){
    data* ptr=(void*)p;
    int n=ptr->threadnum;
    int *threadsum;
    for(int i=5*n;i<(5*n)+5;++i){
        threadsum[0]=threadsum[0]+ptr->arr[i];
    }
    return &threadsum[0];
}
int main(){
    clock_t t;
    t=clock();      //calculate time of execution
    data thread_data[4];
    int num[20];
    for(int i=0;i<20;++i)num[i]=i+1;
    thread_data[0].threadnum=0;
    thread_data[0].arr=num;
    thread_data[1].threadnum=1;
    thread_data[1].arr=num;
    thread_data[2].threadnum=2;
    thread_data[2].arr=num;
    thread_data[3].threadnum=3;
    thread_data[3].arr=num;
    
    pthread_t threads[4];

    pthread_create(&threads[0],NULL,findsum4threads,&thread_data[0]);
    pthread_create(&threads[1],NULL,findsum4threads,&thread_data[1]);
    pthread_create(&threads[2],NULL,findsum4threads,&thread_data[2]);
    pthread_create(&threads[3],NULL,findsum4threads,&thread_data[3]);

    int*sum0,*sum1,*sum2,*sum3;

    pthread_join(&threads[0],(void**)&sum0);
    pthread_join(&threads[1],(void**)&sum1);
    pthread_join(&threads[2],(void**)&sum2);
    pthread_join(&threads[3],(void**)&sum3);


    printf("sum of first nums = %d\n",*sum0+*sum1+*sum2+*sum3);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nTime taken= %.7lf",time_taken);
    return 0;
}