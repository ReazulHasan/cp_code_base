#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

#define size 10000

int main()
{
int i,j,k;
char a[size];
while(gets(a))
    {
    int x=strlen(a),p=0;
    if(x==1&&a[0]=='0')
        break;
    int deg=1,sum=0;
    for(i=0;i<x;i++)
        {
        sum+=a[i]-'0';
        }
    int now=0;
    //cout<<now<<endl;
    while(sum>9)
        {
        now=sum;
        p=0;
        //cout<<sum<<endl;
        while(now>9)
            {
            p+=now%10;
            now/=10;
            }
        p+=now;
        sum=p;
        deg++;
        }
    for(i=0;i<x;i++)
        cout<<a[i];
    if(sum%9==0)
        {
        cout<<" is a multiple of 9 and has 9-degree "<<deg<<"."<<endl;
        }
    else
        cout<<" is not a multiple of 9."<<endl;
    }
return 0;
}
