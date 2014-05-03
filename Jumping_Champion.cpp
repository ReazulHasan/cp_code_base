#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define sz 1000000
int a[sz+3],prim[sz+3];

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int prev=2;
for(i=2;i<=sz;i++)
    {
    if(a[i]==0)
        {
        prim[i]=i-prev;
        prev=i;
        }
    else
        prim[i]=0;
    }
for(i=0;i<20;i++)
    cout<<prim[i]<<" ";
return 0;
}

int main()
{
seive();
return 0;
}
