#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

#define size 5000009

ll flag[size],sum[size],res[size];

int prime()
{
ll i,j;
for(i=2;i<=size;i++)
        {
        if(!flag[i])
            {
            for(j=i+i;j<size;j+=i)
                    {
                    flag[j]=1;
                    sum[j]+=i;
                    }
            }
        }
}

int check()
{
ll i;
res[0]=res[1]=0;
for(i=2;i<=size;i++)
        {
        res[i]=res[i-1];
        if(!flag[sum[i]]||!flag[i])
            res[i]++;
        }
}

int main()
{
prime();
check();
ll a,b;
while(cin>>a&&a)
    {
    cin>>b;
    cout<<res[b]-res[a-1]<<endl;
    }
return 0;
}
