#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<string>
using namespace std;

int flag[1000009],prim[1000009],num[100];

int seive()
{
int i,j,k;
for(i=2;i*i<1000000;)
    {
    for(j=i+i;j<1000000;j+=i)
        flag[j]=1;
    for(i++;flag[i];i++);
    }
k=1;
prim[0]=2;
for(i=3;i<1000000;i+=2)
    if(flag[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int gcd(int a,int b)
{
if(b==0)
    return a;
return gcd(b,a%b);
}

int main()
{
seive();
int i,j,k,m,n;
while(cin>>n>>m)
    {
    int coun=0,x,y,batil,tot=0;
    map<int,int> mp;
    for(i=0;i<m;i++)
        {
        cin>>num[i];
        batil=n/num[i];
        tot+=batil;
        }
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
            {
            long long a=num[i],b=num[j];
            int mn=gcd(a,b);
            long long lcm=(a/mn)*b;
            batil=n/lcm;
            tot-=batil;
            v.push_back(lcm);
            }
    }
return 0;
}
