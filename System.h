#include"RootSelect.h"
//#include"Bridge.h"
#include<stdlib.h>
using namespace std;

class System
{
    public:
        void ShowPut();
        void Run();
        void Login();
        void Register();
        void SysExit();
    private:
        RootSelect *root;
};
