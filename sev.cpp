#include<iostream>
#include<cstdio>
using namespace std;

int a[1000],b[1000];

int main()
{
int i,j,k=0;
for(i=2;i*i<=100;i++)
    for(j=i+i;j<=100;j+=i)
        a[j]=1;
//b[0]=2;
for(i=2;i<100;i++)
    if(a[i]==0)
        b[k++]=i;
for(i=0;i<k;i++)
    cout<<b[i]<<" ";
return 0;
}
