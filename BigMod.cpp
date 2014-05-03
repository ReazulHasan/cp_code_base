#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long recur(long long b,long long p,long long m)
{
if(p==0) return 1;
if(p==1) return b%m;
if(p%2==1)
    return ((recur(b,p-1,m)%m)*(recur(b,1,m)%m))%m;
else
    return ((recur(b,p/2,m)%m)*(recur(b,p/2,m)%m))%m;
}

int main()
{
long long b,p,m,r=100;
while(cin>>b>>p>>m)
    {
    r=recur(b,p,m);
    cout<<r<<endl;
    }
}
