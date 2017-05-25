//from http://www.cnblogs.com/youtherhome/archive/2013/03/17/2964195.html
//Threads.cpp
#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

//线程运行函数
void *thread(void *ptr) 
{
    for(int i = 0;i < 3;i++) {
        sleep(1);
        cout << "This is a pthread." << endl;
    }
    return 0;
}

int main() {
    
    //定义线程标识符
    pthread_t id;
    
    
    /* 创建线程，第一个参数为指向线程标识符的指针，第二个参数用来设置线程属性，第三个参
     * 数是线程运行函数的起始地址，最后一个参数是运行函数的参数。第二个参数设置为NULL生
     * 成默认属性的线程。
     * 创建线程成功返回0，返回非0则创建线程失败。
     * 
     * 创建线程成功后，新创建的线程则运行参数三和参数四确定的函数，原来的线程则继续运行下一行代码。
     * */
    int ret = pthread_create(&id, NULL, thread, NULL);
    
    if(!ret) {
        cout << "Create pthread success!" << endl;
    }
    
    if(ret) {
        cout << "Create pthread error!" << endl;
        return 1;
    }
    for(int i = 0;i < 3;i++) {
        cout <<  "This is the main process." << endl;
        sleep(1);
    }
    /*
     * 函数pthread_join用来等待一个线程的结束,第一个参数为被等待的线程标识符，
     * 第二个参数为一个用户定义的指针，它可以用来存储被等待线程的返回值。
     * 
     * 这个函数是一个线程阻塞的函数，调用它的函数将一直等待到被等待的线程结束为止，
     * 当函数返回时，被等待线程的资源被收回。
     * 
     * 线程结束还可以用pthread_exit函数来结束
     * 
     * 一个线程不能被多个线程等待，否则第一个接收到信号的线程成功返回，其余调用
     * pthread_join的线程则返回错误代码ESRCH。
     * */
    pthread_join(id, NULL);
    return 0;
}
