#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define maxn 10000000

int a[maxn],b[maxn];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=maxn;)
    {
    for(j=i+i;j<=maxn;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
mp[2]=1;
int k=1;
for(i=3;i<=maxn;i++)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
for(i=0;i<=10;i++)
    cout<<b[i]<<" ";
}

int main()
{
seive();
}
