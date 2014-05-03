#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int t,a[50],i,j;
while(cin>>t)
    {
    if(t==0)
        break;
    for(i=1;i<=t;i++)
        {
        int flag=0,pos=100;
        for(j=0;j<5;j++)
            cin>>a[j];
        for(j=0;j<5;j++)
            if(a[j]<=127) //black
                flag+=1;
        if(flag==1)
            {
            for(j=0;j<5;j++)
                if(a[j]<=127)
                    pos=j;
            if(pos==0)
                cout<<"A"<<endl;
            if(pos==1)
                cout<<"B"<<endl;
            if(pos==2)
                cout<<"C"<<endl;
            if(pos==3)
                cout<<"D"<<endl;
            if(pos==4)
                cout<<"E"<<endl;
            }
        else
            cout<<"*"<<endl;

        }
    }
}
