//bismillahir rahmanir rahim
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<map>
using namespace std;

typedef long long ll;
#define size 5000009

ll flag[size+5],res[size+5],prim[size+5];

int prime()
{
ll i,j;
for(i=2;i<=size;i++)
    {
    if(!flag[i])
        {
            for(j=i+i;j<=size;j+=i)
                {
                flag[j]=1;
                prim[j]+=i;
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
        if(!flag[prim[i]]||!flag[i])
            res[i]++;
        }
}

int main()
{
ll a,b;
prime();
check();
while(cin>>a&&a)
    {
    cin>>b;
    cout<<res[b]-res[a-1]<<endl;
    }
return 0;
}
