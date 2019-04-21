#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<arpa/inet.h>
#include<errno.h>
#include<json/json.h>
#include<sys/socket.h>
using namespace std;

class TcpAki
{
    private:

        int ser_fd;

    public:
        TcpAki() {Create();}
        void Create();
        int Accept();
        int Listen();
        int Send(int clifd,const string &val);
        int Recv(int clifd,string &str);
        int GetSerFd();
};
