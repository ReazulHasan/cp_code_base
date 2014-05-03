#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a,b,x,y,t;
cin>>t;
while(t--)
    {
    cin>>a>>b;
    if(a<b||(a%2!=b%2))
        cout<<"impossible"<<endl;
    else
        {
        x=(a+b)/2;
        y=(a-b)/2;
        cout<<x<<" "<<y<<endl;
        }
    }
return 0;
}
