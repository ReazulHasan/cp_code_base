#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

long long x1,k1,d1,x,y,d;

int extended_euclid(long long a,long long b)
{
if(b==0)
    {
    x1=1;
    k1=0;
    d1=a;
    //cout<<x1<<" "<<k1<<" "<<d1<<endl;
    return a;
    }
extended_euclid(b,a%b);
d=d1;
x=k1;
y=x1-(a/b)*k1;
k1=y;
x1=x;
//cout<<x<<" "<<y<<" "<<d<<endl;
return 0;
}

int main()
{
long long a,b,i,j,k;
while(cin>>a>>b)
    {
    extended_euclid(a,b);
    cout<<x<<" "<<y<<" "<<d<<endl;
    }
return 0;
}
