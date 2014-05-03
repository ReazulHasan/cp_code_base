#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define max 1000000

int a[max],b[max],c[max];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=max;i++)
    for(j=i+i;j<=max;j+=i)
        a[j]=1;
int k=0;
for(i=2;i<=max;i++)
    if(a[i]==0)
        {
        b[k++]=i;
        c[i]=1;
        mp[i]=1;
        }
}

int factor(int n)
{
int i,j,k,coun1=0,flag=0;
for(i=0;(b[i]*b[i])<=n;i++)
    {
    if(n%b[i]==0)
        {
        coun1=c[n/b[i]]+1;
        c[n]=coun1;
        flag=1;
        }
    if(flag==1)
        break;
    }
return coun1;
}

int main()
{
seive();
//return 0;
int n,i,j,k;
while(cin>>n)
    {
    int coun=0;
    for(i=2;i<=n;i++)
        {
        int x=i;
        if(mp[x]==1)
            coun++;
        else
            {
            if(x%2==0)
                {
                c[i]=(c[x/2]+1);
                coun+=c[i];
                }
            else
                coun+=factor(x);
            }
        //cout<<coun<<" ";
        }
    cout<<coun<<endl;
    }
return 0;
}
