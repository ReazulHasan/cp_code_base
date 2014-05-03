#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define sz 1000000
int a[sz+3],b[sz+3];
long long it,hip;

int seive()
{
int i,j;
for(i=2;i*i<sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
int k=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
}

int div(long long now)
{
long long i,j,mult=1,n=now;
for(i=0;b[i]*b[i]<=now;i++)
    {
    int coun=0;
    while(now%b[i]==0)
        {
        coun++;
        now/=b[i];
        }
    if(coun>0)
        mult*=(coun+1);
    }
if(now>1)
    mult*=2;
if(mult>hip)
    {
    hip=mult;
    it=n;
    }
return 0;
}

int main()
{
seive();
long long lo,hi,i,j,t;
cin>>t;
while(t--)
    {
    hip=0; it=0;
    cin>>lo>>hi;
    for(i=lo;i<=hi;i++)
        div(i);
    cout<<"Between "<<lo<<" and "<<hi<<", "<<it<<" has a maximum of "<<hip<<" divisors."<<endl;
    }
return 0;
}
