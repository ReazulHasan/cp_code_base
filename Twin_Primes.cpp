#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define size 30000000
int a[size],b[size],p[size],q[size];

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
int k=1;
for(i=3;i<size;i++)
    if(a[i]==0)
        b[k++]=i;
int x=1;
for(i=0;i<k-1;i++)
    {
    if((b[i]+2)==b[i+1])
        {
        p[x]=b[i];
        q[x]=b[i+1];
        x++;
        }
    }
}

int main()
{
seive();
int n;
while(cin>>n)
    {
    cout<<"("<<p[n]<<", "<<q[n]<<")"<<endl;
    }
return 0;
}
