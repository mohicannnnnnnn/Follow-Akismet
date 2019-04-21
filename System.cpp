#include"System.h"
#include "Bridge.h"

void System::ShowPut()
{
    cout<<"                "<<endl;
    cout<<"====ViewList===="<<endl;
    cout<<"====1.Login ===="<<endl;
    cout<<"====2.Register=="<<endl;
    cout<<"====3.SysExit==="<<endl;
    cout<<"                "<<endl;
    cout<<"Please input Your Choice"<<endl;
}

void System::Run()
{
    Bridge::GetBridge()->Connect();
    int n =0;
    while(1)
    {
        ShowPut();
        cin>>n;
        switch(n)
        {
            case 1:Login();
                   break;
            case 2:Register();
                   break;
            case 3:
                   exit (0);
            default:
                   cout<<"input error"<<endl;
        }
    }

}


void System::Login()
{
    string id,passwd;
    cout<<"ID:";
    cin>>id;
    cout<<endl;
    cout<<"PASSWORD:";
    cin>>passwd;
    //  Json::Value val;
    // val["id"] =id;
    //  val["paddwd"] = passwd;
    //  Bridge::getBridge()->>

    if(strcmp(id.c_str(),"tyf"))
    {
        cout<<"=== Login Successful ==="<<endl;
        Bridge::GetBridge()->SendBridge(id);

        string getstr;
        Bridge::GetBridge()->RecvBridge(getstr);
        cout<<"get str is :"<<getstr<<endl;

        //跳转到RootSelect 函数
        root->RunChoice();

    }
    else
    {
        cout<<"===LOgin Failed! ==="<<endl;
        return ;
    }

}

void System::Register()
{
    int id ,passwd;
    cout<<"ID";
    cin>>id;
    cout<<"PADDWORD:";
    cin>>passwd;
    // Json::Valuse val;
    // val["id"] = id ;
    // val["passwd"] = passwd;

    if(id == -1 )
    {
        cout<<"===Register Successful==="<<endl;
        cout<<"Ready to Login"<<endl;
        Login();
    }
    else
    {
        cout<<"==Register  Faile!==="<<endl;
    }
}

void System::SysExit()
{
    return ;
}

/*
   int main()
   {
   System sys;
   sys.Run();
   return 0;
   }
   */
