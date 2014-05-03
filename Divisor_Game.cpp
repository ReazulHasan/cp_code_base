#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int flag[1000009],prim[1000009],divi[1000009],res[1000009];
map<int,int> mp;

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
mp[2]=1;
divi[2]=2;
for(i=3;i<1000000;i+=2)
    if(flag[i]==0)
        {
        prim[k++]=i;
        mp[i]=1;
        divi[i]=2;
        }
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int coun_div(int x)
{
int i,j,k,tot=1;
for(i=0;prim[i]*prim[i]<=x;i++)
    {
    if(x%prim[i]==0)
        {
        int coun=0;
        while(x%prim[i]==0&&x>1)
            {
            coun++;
            x/=prim[i];
            }
        coun++;
        tot*=coun;
        }
    }
if(x>1)
    tot*=2;
return tot;
}

int main()
{
seive();
int i,j,k;
for(i=1;i<=1000000;i++)
    if(mp[i]==0)
        divi[i]=coun_div(i);
res[1]=1;
for(i=2;i<=1000000;i++)
    {
    if(divi[i]>=divi[i-1])
        res[i]=i;
    else
        {
        divi[i]=divi[i-1];
        res[i]=res[i-1];
        }
    }
int t,x;
cin>>t;
while(t--)
    {
    cin>>x;
    cout<<res[x]<<endl;
    }
return 0;
}
