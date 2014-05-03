#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int prim[10000009],flg[10000009];
int k;

int seive()
{
int i,j;
for(i=2;i*i<=1000000;)
    {
    for(j=i+i;j<=1000000;j+=i)
        flg[j]=1;
    for(i++;flg[i];i++);
    }
prim[0]=2;
k=1;
for(i=3;i<=1000000;i+=2)
    if(flg[i]==0)
        prim[k++]=i;
//cout<<prim[k-1]<<endl;
return 0;
}

int main()
{
int i,j,cas=0;
seive();
long long n;
while(cin>>n&&n)
    {
    long long res=0;
    cas++;
    long long a=n;
    int flag=0;
    i=0;
    long long mot=(long long) prim[i]*prim[i];
    while(mot<=a&&i<k)
        {
        //cout<<prim[i]<<" "<<mot<<endl;
        if(a%prim[i]==0)
            {
            flag++;
            long long mult=1;
            while(a%prim[i]==0&&a>0)
                {
                mult*=prim[i];
                a/=prim[i];
                }
            res+=mult;
            }
        i++;
        mot=(long long) prim[i]*prim[i];
        }
    if(a>1)
        {
        flag++;
        res+=a;
        }
    if(flag==0)
        res+=1;
    if(n==1)
        res+=1;
    if(flag==1)
        res=n+1;
    cout<<"Case "<<cas<<": "<<res<<endl;
    }
return 0;
}
