#include"TcpAki.h"

void TcpAki::Create()
{
    ser_fd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == ser_fd)
    {
        cerr<<"ser_fd creat fail;errno:"<<endl;
        return ;
    }
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int ser_flag = bind(ser_fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ser_flag < 0)
    {
        cerr<<"ser_fd bind fail;errno:"<<errno<<endl;
        return ;
    }
}

int TcpAki::Accept()
{
    struct sockaddr_in caddr;
    socklen_t len = sizeof(caddr);
    int clifd = accept(ser_fd,(struct sockaddr*)&caddr,&len);
    if(-1 == clifd)
    {
        cerr<<"accept client fail;errno:"<<errno<<endl;
        return 0;
    }
    return clifd;
}

int TcpAki::Listen()
{

    int flag = listen(ser_fd,20);
    if(flag < 0)
    {
        cerr<<"fd listen fail;errno:"<<endl;
        return 0;
    }
    return flag;
}


int TcpAki::Send(int clifd,const string &val)
{
    int flag = send(clifd,val.c_str(),strlen(val.c_str()),0);
    if(flag == -1)
    {
        cerr<<"send reason fail;errno:"<<errno<<endl;
        return 0;
    }
    return flag;
}

int TcpAki::Recv(int clifd,string &str)
{
    char buff[100] = {0};
    int flag =  recv(clifd,buff,99,0);
    if(flag == -1)
    {
        cerr<<"recv  fail;errno:"<<errno<<endl;
        return 0;
    }
    str = buff;
    return flag;
}

int TcpAki::GetSerFd()
{
    return ser_fd;
}

