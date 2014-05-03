#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<set>
using namespace std;

vector<int> graph[1000];

int BFS(int s,int d)
{
queue<int> q;
int color[100],cost[100],i;
q.push(s);
for(i=0;i<100;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
color[s]=1;
cost[s]=0;
while(!q.empty())
    {
    int now=q.front();
    q.pop();
    if(now==d)
        return cost[now];
    for(i=0;i<graph[now].size();i++)
        {
        if(color[graph[now][i]]==0)
            {
            color[graph[now][i]]=1;
            cost[graph[now][i]]=cost[now]+1;
            q.push(graph[now][i]);
            }
        }
    }
return 0;
}

int main()
{
int i,n,a,b,x,coun=0,m,s,d,j,res;
while(cin>>n)
    {
    coun++;
    for(i=0;i<1000;i++)
        graph[i].clear();
    for(i=0;i<n;i++)
        {
        cin>>x;
        graph[0].push_back(x-1);
        graph[x-1].push_back(0);
        }
    for(i=1;i<19;i++)
        {
        cin>>a;
        for(j=0;j<a;j++)
            {
            cin>>x;
            graph[i].push_back(x-1);
            graph[x-1].push_back(i);
            }
        }
    cin>>m;
    cout<<"Test Set #"<<coun<<endl;
    for(i=0;i<m;i++)
        {
        cin>>s>>d;
        res=BFS(s-1,d-1);
        printf("%2d to %2d: %d",s,d,res);
        cout<<endl;
        }
    cout<<endl;
    }
return 0;
}
