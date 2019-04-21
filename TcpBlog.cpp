#include"TcpBlog.h"
void TcpBlog::Create()
{
    fd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == fd)
    {
        cerr<<"clifd creat fail;errnoz:"<<errno<<endl;
        return ;
    }
}


int TcpBlog::Connect()
{
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int flag  = connect(fd,(struct sockaddr*)&saddr,sizeof(saddr));
     if(flag == -1)
    {
        cerr<<"clifd connect fail;errno:"<<errno<<endl;
        return 0;
    }
    return flag;
}

int TcpBlog::Send(const string &val)
{
    int flag = send(fd,val.c_str(),strlen(val.c_str()),0);
    if(flag == -1)
    {
        cerr<<"send reason fail;errno:"<<errno<<endl;
        return 0;
    }
    return flag;
}

int  TcpBlog::Recv( string &str)
{
    char buff[100] = {0};
    int flag =  recv(fd,buff,99,0);
    if(flag == -1)
    {
        cerr<<"recv  fail;errno:"<<errno<<endl;
        return 0;
    }
    str = buff;
    return flag;
}

int TcpBlog::GetBlogFd()
{
    return fd;
}

