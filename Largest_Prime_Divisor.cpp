#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

#define sz 10000000
long long a[sz+3],b[sz+3];

int seive()
{
long long i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
int k=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
return 0;
}

int fact(long long x)
{
vector<long long> v;
long long i,j;
for(i=0;b[i]*b[i]<=x;i++)
    {
    int fl=0;
    while(x%b[i]==0)
        {
        fl=1;
        x/=b[i];
        }
    if(fl==1)
        v.push_back(b[i]);
    }
//cout<<x<<endl;
if(x>1)
    v.push_back(x);
int len=v.size();
//cout<<len<<endl;
if(len==1||len==0)
    cout<<"-1"<<endl;
else
    {
    sort(v.begin(),v.end());
    cout<<v[len-1]<<endl;
    }
return 0;
}

int main()
{
seive();
long long n,i,j;
int flag=0;
while(cin>>n&&n)
    {
    flag=1;
    if(n<0)
        {
        flag=-1;
        n*=-1;
        }
    fact(n);
    }
return 0;
}
