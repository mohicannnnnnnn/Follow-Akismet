#include"RootSelect.h"

void RootSelect::Show()
{
    cout<<"———————————————————Operates————————————————————————"<<endl;
    cout<<"===1.Show : Show the  Operator   ==="<<endl;
    cout<<"===2.Insert : Tip the Baleful Usages To Akismet ==="<<endl;
    cout<<"===3.Delect : Cancle The Tip To Akismet==="<<endl;
    cout<<"===4.Search : Search The Usages In Akismet BaleFul Usages List ==="<<endl;
  //  cout<<"===5.Update==="<<endl;
    cout<<"===5.Exit  ==="<<endl;
    cout<<" ——————————————————————————————————————————————— "<<endl;
    cout<<"Please Input Your Choice"<<endl;
}

void RootSelect::RunChoice()
{
    int n = 0;
    while(1)
    {
        Show();
        cin>>n;
        switch(n)
        {
            case 1:Show();
                   break;
            case 2:Insert();
                   break;
            case 3:Delect();
                   break;
            case 4:Search();
                   break;
         //   case 5:Update();
           //        break;
            case 5:Exit();
                   break;
            default:
                   cout<<"Input Error"<<endl;
        }
    }
}
void RootSelect::Insert()
{
    cout<<"Insert"<<endl;
}
void RootSelect::Delect()
{
    cout<<"Delect"<<endl;

}

void RootSelect::Search()
{
    cout<<"Search"<<endl;

}
void RootSelect::Update()
{
    cout<<"Update"<<endl;
}

void RootSelect::Exit()
{
    exit(0);
}

/*
int main()
{
    cout<<"Thanks For Using Akismet ,You Can Use It To Mauntain Your Blog Environment "<<endl;
    RootSelect root;
    root.RunChoice();
    return 0;
}*/
