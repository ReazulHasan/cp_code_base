#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int n,a,b,i;
while(cin>>n&&n)
    {
    int x=n,res=0;
    while(x>=3)
        {
        res+=x/3;
        x=x/3+x%3;
        //cout<<res<<" "<<x<<endl;
        }
    if(n>=3&&x==2)
        res++;
    cout<<res<<endl;
    }
}
