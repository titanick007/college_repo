#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct{
    int *arr;
    int th_num;
}data;
void *halfsum(void *p){
    data* ptr=(data*)p;
    int n=ptr->th_num;
    int* thread_sum=(int*)calloc(1,sizeof(int));
    if(n==0){
        for(int i=0;i<10;++i){
            thread_sum[0]=thread_sum[0]+ptr->arr[i];
        }
    }
    else{
        for(int i=10;i<20;++i)
        thread_sum[0]=thread_sum[0]+ptr->arr[i];
    }
    pthread_exit(thread_sum);
}
int main(){
    clock_t t;
    t=clock();      //calculate time of execution
    data thread_data[2];
    int nums[20];
    for(int i=0;i<20;++i)nums[i]=i+1;
    //providing thread data
    thread_data[0].arr=nums;
    thread_data[0].th_num=0;
    thread_data[1].th_num=1;
    thread_data[1].arr=nums;

    pthread_t tid[2];
    pthread_create(&tid[0],NULL,halfsum,&thread_data[0]);
    pthread_create(&tid[1],NULL,halfsum,&thread_data[1]);
    int *sumh1;
    int *sumh2;
    //retrieve thread result
    pthread_join(tid[0],(void**)&sumh1);
    pthread_join(tid[1],(void**)&sumh2);

    printf("Sum of 20 integers = %d\n",*sumh1+*sumh2);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nTime taken= %.7lf",time_taken);
    return 0;
}