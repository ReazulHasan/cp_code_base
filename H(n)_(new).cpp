#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
long long i,j,k,cas;
cin>>cas;
while(cas--)
    {
    long long n;
    cin>>n;
    long long res=0,a=0,b=0,last;
    if(n>0)
        {
        for(i=1;i*i<=n;i++)
            {
            long long x=i;
            a=n/x;
            last=a;
            res+=a;
            int dif=b-a;
            if(dif>0)
                {
                long long p=0;
                p=dif*(x-1);
                res+=p;
                }
            b=a;
            }
        for(j=i;j<=last;j++)
            {
            //cout<<"hi "<<j<<endl;
            res+=n/j;
            }
        }
    cout<<res<<endl;
    }
return 0;
}
