#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define maxn 50000
vector<int> v[maxn];
int color[maxn];
int coun=0;

int dfs(int n)
{
//coun++;
color[n]=1;
int x=v[n].size();
int i,j;
for(i=0;i<x;i++)
    {
    int it=v[n][i];
    if(color[it]==0)
        {
        coun++;
        dfs(it);
        }
    }
return 0;
}

int main()
{
int t,i,j,m,n,l,x,y;
cin>>t;
while(t--)
    {
    for(i=0;i<maxn;i++)
        v[i].clear();
    for(j=0;j<maxn;j++)
        color[j]=0;
    cin>>m>>n>>l;
    for(i=1;i<=n;i++)
        {
        cin>>x>>y;
        v[x].push_back(y);
        }
    int res=0;
    for(i=1;i<=l;i++)
        {
        coun=0;
        cin>>x;
        if(color[x]==0)
            {
            coun++;
            dfs(x);
            }
        res+=coun;
        }
    cout<<res<<endl;
    }
}
