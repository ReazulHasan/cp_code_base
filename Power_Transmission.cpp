#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int cap[1000],cost[1000][1000],color[1000],prev[1000];
vector<int> v[1000];
int inf=98765469;

int BFS(int hi)
{
int i,j,k;
queue<int> q;
for(i=0;i<=hi;i++)
    {
    color[i]=0;
    prev[i]=-1;
    }
cap[hi]=inf;
color[0]=1;
prev[0]=-1;
q.push(0);
int fl=0;
while(!q.empty())
    {
    int first=q.front();
    q.pop();
    if(first==hi)
        break;
    int len=v[first].size();
    for(i=0;i<len;i++)
        {
        int sec=v[first][i];
        if(color[sec]==0&&cost[first][sec]>0&&cap[sec]>0)
            {
            color[sec]=1;
            prev[sec]=first;
            q.push(sec);
            }
        }
    }
int last=hi,fin=inf;
while(prev[last]>-1)
    {
    int bef=prev[last];
    int cos=cost[bef][last];
    if(fin>cos)
        fin=cos;
    cos=cap[bef];
    if(fin>cos)
        fin=cos;
    last=bef;
    }
last=hi;
while(prev[last]>-1)
    {
    int bef=prev[last];
    cost[bef][last]-=fin;
    cost[last][bef]+=fin;
    cap[bef]-=fin;
    last=bef;
    }
if(fin==inf)
    return 0;
return fin;
}

int main()
{
int nod,edg,i,j,k,x,y,c,flag=0;
while(cin>>nod)
    {
    cap[0]=inf;
    for(i=1;i<=nod;i++)
        cin>>cap[i];
    cin>>edg;
    for(i=1;i<=edg;i++)
        {
        cin>>x>>y>>c;
        cost[x][y]=c;
        v[x].push_back(y);
        }
    cin>>x>>y;
    for(i=1;i<=x;i++)
        {
        cin>>c;
        cost[0][c]=inf;
        v[0].push_back(c);
        }
    for(i=1;i<=y;i++)
        {
        cin>>c;
        cost[c][nod+1]=inf;
        v[c].push_back(nod+1);
        }
    int res=0;
    while(true)
        {
        int p=BFS(nod+1);
        if(p==0)
            break;
        else
            res+=p;
        }
    if(flag)
        cout<<endl;
    flag=1;
    cout<<res;
    for(i=0;i<=nod+1;i++)
        {
        for(j=0;j<=nod+1;j++)
            {
            cost[i][j]=0;
            }
        cap[i]=0;
        color[i]=0;
        prev[i]=0;
        }
    }
return 0;
}
