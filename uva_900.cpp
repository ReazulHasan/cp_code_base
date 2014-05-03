#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int i,n;
long long a=1,b=2,c,d;
while(scanf("%d",&n)==1)
    {
    if(n==0) break;
    if(n==1) cout<<a<<endl;
    else if(n==2) cout<<b<<endl;
    else
        {
        d=a;
        for(i=3;i<=n;i++)
            {
            c=d+b;
            d=b;
            b=c;
            }
        cout<<b<<endl;
        }
    a=1; b=2;
    }
return 0;
}
