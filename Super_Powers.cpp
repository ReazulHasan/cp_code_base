#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define sz 100
int a[sz+3],b[sz+3];
map<int,int> mp;
map<unsigned long long,int> mpho;
//unsigned long long maxn=18446744073709551615;

int seive()
{
int i,j;
for(i=2;i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=1;
b[0]=2;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
}

int main()
{
unsigned long long i,j,k;
vector<unsigned long long> v;
seive();
for(i=2;i<=65535;i++)
    {
    unsigned long long bas=i;
    unsigned long long mult=1;
    int flag=0;
    for(j=4;j<=62;j++)
        {
        mult=1;
        if(mp[j]==0)
            {
            for(k=1;k<=j;k++)
                {
                if(((64log2(2))/bas)<mult)
                    {
                    flag=1;
                    break;
                    }
                mult*=bas;
                }
            if(mpho[mult]==0)
                {
                v.push_back(mult);
                mpho[mult]=1;
                }
            }
        if(flag==1)
            break;
        }
    }
sort(v.begin(),v.end());
unsigned len=v.size();
for(i=0;i<len;i++)
    cout<<v[i]<<" ";
return 0;
}
