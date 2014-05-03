#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int n,i,j;
char a[1000],b[1000];
while(cin>>n>>a)
    {
    int x=strlen(a);
    if(n==0&&a[0]=='0'&&x==1)
        break;
    int k=0;
    for(i=0;i<x;i++)
        if((a[i]-'0')!=n)
            b[k++]=a[i];
    int flag=0;
    for(i=0;i<k;i++)
        {
        if(b[i]>'0')
            flag=1;
        if(flag==1)
            cout<<b[i];
        }
    if(flag==0)
        cout<<"0";
    cout<<endl;
    }
return 0;
}
