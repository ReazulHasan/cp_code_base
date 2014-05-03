#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int a,b,i,j,t;
char c;
cin>>t;
while(t--)
    {
    cin>>c>>a>>b;
    if(c=='r')
        {
        if(a<b)
            cout<<a<<endl;
        else
            cout<<b<<endl;
        }
    if(c=='k')
        {
        if((a*b)%2==0)
            cout<<(a*b)/2<<endl;
        else
            cout<<(a*b)/2+1<<endl;
        }
    if(c=='Q')
        {
        if(a<b)
            cout<<a<<endl;
        else
            cout<<b<<endl;
        }
    if(c=='K')
        {
        if(a%2==0)
            a/=2;
        else
            {
            a/=2;
            a++;
            }
        if(b%2==0)
            b/=2;
        else
            {
            b/=2;
            b++;
            }
        cout<<a*b<<endl;
        }
    }
return 0;
}
