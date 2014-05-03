#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;

vector<int> v[500];
set<int> myset;
int color[500],total=0,cost[500];

int BFS()
{
set<int>::iterator it;
for(it=myset.begin();it!=myset.end();it++)
    {
    queue<int> q;
    int now=*it;
    for(int i=0;i<=100;i++)
        {
        color[i]=0;
        cost[i]=0;
        }
    color[now]=1;
    cost[now]=0;
    q.push(now);
    while(!q.empty())
        {
        int x=q.front();
        q.pop();
        int len=v[x].size();
        for(int i=0;i<len;i++)
            {
            int y=v[x][i];
            if(color[y]==0)
                {
                color[y]=1;
                cost[y]=cost[x]+1;
                total+=cost[y];
                q.push(y);
                }
            }
        }
    //cout<<now<<endl;
    }
return 0;
}

int main()
{
int i,j,k,x,y,cas=0;
while(cin>>x>>y)
    {
    cas++;
    if(x==0&&y==0)
        break;
    while(1)
        {
        if(x==0&&y==0)
            break;
        v[x].push_back(y);
        myset.insert(x);
        myset.insert(y);
        cin>>x>>y;
        }
    int sz=myset.size();
    int jora=sz*(sz-1);
    total=0;
    BFS();
    //cout<<total<<" "<<jora<<endl;
    double p=total*1.0,q=jora*1.0;
    double fin=(p/q)*1.0;
    printf("Case %d: average length between pages = %.3lf clicks\n",cas,fin);
    myset.clear();
    for(i=0;i<=100;i++)
        v[i].clear();
    //cout<<fin<<endl;
    }
return 0;
}
