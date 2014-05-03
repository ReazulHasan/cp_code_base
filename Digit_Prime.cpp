#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define size 1000000
int a[size],b[size],c[size];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=size;)
    {
    for(j=i+i;j<=size;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
mp[2]=1;
int k=1;
for(i=3;i<=size;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
for(i=0;i<k;i++)
    {
    int now=b[i],sum=0;
    while(now>9)
        {
        sum+=now%10;
        now/=10;
        }
    sum+=now;
    if(mp[sum]==1)
        c[b[i]]=1;
    }
for(i=2;i<=size;i++)
    c[i]=c[i]+c[i-1];
}

int main()
{
seive();
int t,a,b;
cin>>t;
while(t--)
    {
    scanf("%d %d",&a,&b);
    int res=c[b]-c[a-1];
    printf("%d\n",res);
    }
return 0;
}
