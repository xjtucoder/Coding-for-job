#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

void* say_hello(void* args)
{
    cout<<"hello in thread "<<*((int*)args)<<endl;
    int status = 10+ *((int*)args); //线程退出时添加退出的信息，status供主程序提取该线程的结束信息
    pthread_exit((void*)status);
}

int main()
{
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    
    pthread_attr_t attr; //线程属性结构体，创建线程时加入的参数
    pthread_attr_init(&attr); //初始化
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    for(int i=0;i<NUM_THREADS;++i)
    {
        indexes[i]=i;
        int ret=pthread_create(&tids[i], &attr, say_hello, (void*)&(indexes[i]));
        if(ret!=0)
        {
            cout<< "pthread_create error:eror_code " << ret <<endl;
        }
    }
    pthread_attr_destroy(&attr); //释放内存
    void* status;
    for(int i=0;i<NUM_THREADS;++i)
    {
        int ret=pthread_join(tids[i],&status); //主程序join每个线程后取得线程退出的信息status
        if(ret!=0)
        {
            cout<< "pthread_join error:eror_code " << ret <<endl;
        }
        else
        {
            cout<< "pthread_join get status: " << (long)status <<endl;
        }
    }
    
    return 0;
}
