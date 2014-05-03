#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int memo[10000009];
vector<int> v;

int acc(int x)
{
int p=0;
do
    {
    if(x%2==0)
        x/=2;
    else
        x=x*3+1;
    p++;
    }
while(x!=1);
return p;
}

int main()
{
long long i,j,k;
int maxn=0,num,val;
for(i=1;i<=1000000;i++)
    {
    long long now=i;
    int coun=0;
    if(memo[now]==0)
        {
        do
            {
            if(now%2==0)
                now/=2;
            else
                now=(now*3+1);
            coun++;
            if(now<=1000000LL)
            if(memo[now]==0)
                {
                memo[now]=coun;
                v.push_back(now);
                }
            }
        while(now!=1);
        memo[i]=coun;
        }
    else
        coun=memo[i];
    int sz=v.size();
    for(j=0;j<sz;j++)
        {
        int num=v[j];
        memo[num]=coun-memo[num];
        }
    v.clear();
    }
long long a,b;
while(cin>>a>>b)
    {
    if(a==0&&b==0)
        break;
    if(a>b)
        {
        long long temp=a;
        a=b;
        b=temp;
        }
    int coun,maxn=0;
    for(i=a;i<=b;i++)
        {
        if(memo[i]==0)
            coun=acc(i);
        else
            coun=memo[i];
        if(coun>maxn)
            {
            maxn=coun;
            num=i;
            val=coun;
            }
        }
    cout<<"Between "<<a<<" and "<<b<<", "<<num<<" generates the longest sequence of "<<val<<" values."<<endl;
    }
return 0;
}
