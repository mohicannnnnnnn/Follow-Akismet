#pragma once
#include"TcpBlog.h"
#include<iostream>
#include<pthread.h>
extern pthread_mutex_t mutx ; 

using namespace std;

class Bridge
{
    private:

        Bridge(){ _blog = new TcpBlog();}

        static Bridge * _bridge;

        TcpBlog * _blog;

    public:

        static Bridge* GetBridge()
        {
            if(NULL == _bridge)
            {
                pthread_mutex_lock(&mutx);
                if(NULL == _bridge)
                {
                    _bridge = new Bridge();
                }
                pthread_mutex_unlock(&mutx);
            }
            return _bridge;
        }

        int Connect();
        int SendBridge(const string &val);
        int RecvBridge(string &str);
        int GetFdBridge();
};
ystem.o RootSelect.o TcpBlog.o Bridge.o

