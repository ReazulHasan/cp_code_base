
//not accepted

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int a[1000000],tot[1000000],prev[1000000],n;

int LIS()
{
int i,j,k;
int hi=0,last=0;
for(i=1;i<=n;i++)
    {
    int child=-1,maxn=0;
    for(j=i-1;j>=0;j--)
        if(a[i]>a[j])
            if(tot[j]>maxn)
            {
            maxn=tot[j];
            child=j;
            }
    tot[i]=maxn+1;
    prev[i]=child;
    if(hi<tot[i])
        {
        hi=tot[i];
        last=i;
        }
    }
cout<<hi<<endl;
return 0;
}

int main()
{
int t,i,j,k;
cin>>t;
while(t--)
    {
    cin>>n;
    a[0]=0;
    for(i=1;i<=n;i++)
        cin>>a[i];
    LIS();
    for(i=0;i<=n;i++)
        {
        a[i]=0;
        prev[i]=0;
        tot[i]=0;
        }
    }
return 0;
}
