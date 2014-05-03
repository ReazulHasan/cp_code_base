#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;

# define size 100009
int main()
{
int a[size],b[size],i,j,k,m,n,index=1;
for(i=2;i*i<=size;i++)
    for(j=2;i*j<=size;j++)
        a[i*j]=1;
for(i=0;i<size;i++)
    b[i]=0;
b[2]=2;
for(i=3;i<=size;i++)
    if(a[i]!=1)
        b[i]=i;
/*for(i=0;i<size;i++)
    cout<<b[i]<<" ";*/
while(cin>>m>>n)
    {
    double res;
    int count=0;
    for(i=m;i<=n;i++)
        {
        int euler=i*i+i+41;
        if(b[euler]!=0)
            count++;
        }
    //cout<<count<<" ";
    int p=n-m+1;
    res=(double)count/p;
    res*=100;
    printf("%.2lf\n",res);
    }
return 0;
}
