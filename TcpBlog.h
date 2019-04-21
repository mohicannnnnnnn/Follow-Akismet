#include<iostream>
#include<string.h>
#include<string>
#include<json/json.h>
#include<errno.h>
#include<arpa/inet.h>
using namespace std;

class TcpBlog
{
    private:

        int fd;

    public:
        TcpBlog(){Create();};
        void Create();
        int Connect();
        int Send(const string &val);
        int Recv( string &str);
        int GetBlogFd();
};
