#include<iostream>
#include<cstdio>
using namespace std;

long long over=622702080,under=10000;

int main()
{
int n;
while(cin>>n)
    {
    int i,flag=0,coun=0;
    long long mult=1;
    if(n<0)
        {
        n*=-1;
        if(n%2==0)
            cout<<"Underflow!"<<endl;
        else
            cout<<"Overflow!"<<endl;
        }
    else if(n==13)
        cout<<"6227020800"<<endl;
    else if(n==12)
        cout<<"479001600"<<endl;
    else if(n<=11)
        {
        for(i=2;i<=n;i++)
            mult*=i;
        if(mult<10000)
            cout<<"Underflow!"<<endl;
        else
            cout<<mult<<endl;
        }
        //cout<<mult<<endl;
    else
        cout<<"Overflow!"<<endl;
    }
return 0;
}
