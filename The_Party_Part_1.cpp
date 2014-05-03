#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int color[1500],cost[1500];
vector<int> v[1500];

int bfs(int x)
{
queue<int> q;
int i,j;
color[x]=1;
cost[x]=0;
q.push(x);
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    int len=v[it].size();
    for(i=0;i<len;i++)
        if(color[v[it][i]]==0)
            {
            int m=v[it][i];
            color[m]=1;
            cost[m]=cost[it]+1;
            q.push(m);
            }
    }
return 0;
}

int main()
{
int t,per,edg,i,j,k;
cin>>t;
while(t--)
    {
    for(i=0;i<1500;i++)
        {
        v[i].clear();
        cost[i]=0;
        color[i]=0;
        }
    int a,b;
    cin>>per>>edg;
    for(k=0;k<edg;k++)
        {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        }
    bfs(0);
    for(i=1;i<per;i++)
        cout<<cost[i]<<endl;
    if(t>0)
        cout<<endl;
    }
return 0;
}
