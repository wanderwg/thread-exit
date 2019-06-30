#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//体会线程退出的几种方式
void* thr_entry(void* arg){
  // pthread_exit(NULL);退出线程
    pthread_cancel((pthread_t)arg);
    while(1){
        printf("i am common thread-----%s\n",(char*)arg);
        sleep(1);
   }
    return NULL;
}

int main()
{
    pthread_t mtid;
    mtid=pthread_self();
    //int pthread_create(pthread_t *thread,const pthread_attr_t *attr,
    //                   void*(*start_routine)(void*),void *arg);
    pthread_t tid;
    char* param="this is input param";
    int ret=pthread_create(&tid,NULL,thr_entry,(void*)mtid);
    if(ret!=0)
    {
        printf("pthread create error\n");
        return -1;
    }
    printf("tid:%p\n",tid);
    
    //pthread_cancel(tid);//取消普通线程
    while(1){
        printf("i am main thread-----\n");
        sleep(1);
    }
    return 0;
}
