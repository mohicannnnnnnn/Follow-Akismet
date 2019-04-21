#include"Bridge.h"

Bridge* Bridge::_bridge = NULL;

pthread_mutex_t mutx = PTHREAD_MUTEX_INITIALIZER;    

int Bridge::Connect()
{
    return _blog->Connect();
}

int Bridge::SendBridge(const string &val)
{
    return _blog->Send(val);
}

int Bridge::RecvBridge(string &str)
{
    return _blog->Recv(str);
}

int Bridge::GetFdBridge()
{
    return _blog->GetBlogFd();
}

