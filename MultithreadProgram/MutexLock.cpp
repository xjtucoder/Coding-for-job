#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5
int sum = 0; //定义全局变量，让所有线程同时写，这样就需要锁机制
pthread_mutex_t sum_mutex; //互斥锁
void* say_hello( void* args )
{
    cout << "hello in thread " << *(( int * )args) << endl;
    pthread_mutex_lock( &sum_mutex ); //先加锁，再修改sum的值，锁被占用就阻塞，直到拿到锁再修改sum;
    cout << "before sum is " << sum << " in thread " << *( ( int* )args ) << endl;
    sum += *( ( int* )args );
    cout << "after sum is " << sum << " in thread " << *( ( int* )args ) << endl;
    pthread_mutex_unlock( &sum_mutex ); //释放锁，供其他线程使用
    pthread_exit( 0 );
}
int main()
{
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    pthread_attr_t attr; //线程属性结构体，创建线程时加入的参数
    pthread_attr_init( &attr ); //初始化
    pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_JOINABLE ); //是设置你想要指定线程属性参数，这个参数表明这个线程是可以join连接的，
    //join功能表示主程序可以等线程结束后再去做某事，实现了主程序和线程同步功能
    pthread_mutex_init( &sum_mutex, NULL ); //对锁进行初始化
    for( int i = 0; i < NUM_THREADS; ++i )
    {
        indexes[i] = i;
        int ret = pthread_create( &tids[i], &attr, say_hello, ( void* )&( indexes[i] ) ); //5个进程同时去修改sum
        if( ret != 0 )
        {
            cout << "pthread_create error:error_code=" << ret << endl;
        }
    }
    pthread_attr_destroy( &attr ); //释放内存
    void *status;
    for( int i = 0; i < NUM_THREADS; ++i )
    {
        int ret = pthread_join( tids[i], &status ); //主程序join每个线程后取得每个线程的退出信息status
        if( ret != 0 )
        {
            cout << "pthread_join error:error_code=" << ret << endl;
        }
    }
    cout << "finally sum is " << sum << endl;
    pthread_mutex_destroy( &sum_mutex ); //注销锁
    
    return 0;
}
