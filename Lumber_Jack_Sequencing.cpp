#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
int i,a[20],j,k,cas,b[20];
cin>>cas;
cout<<"Lumberjacks:"<<endl;
while(cas--)
    {
    for(i=0;i<10;i++)
        {
        cin>>k;
        a[i]=k;
        b[i]=k;
        }
    sort(b,b+10);
    int flag1=0,flag2=0;
    for(i=0;i<10;i++)
        if(a[i]!=b[i])
            {
            flag1=1;
            break;
            }
    j=9;
    for(i=0;i<10;i++)
        {
        if(b[i]!=a[j])
            {
            flag2=1;
            break;
            }
        j--;
        }
    if(flag1==0||flag2==0)
        cout<<"Ordered"<<endl;
    else
        cout<<"Unordered"<<endl;
    }
return 0;
}
