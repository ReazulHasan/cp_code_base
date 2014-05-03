#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<int> v[1000];
queue<int> q;
int color[1000],s;

int BFS()
{
int x=1,i;
for(i=0;i<1000;i++)
    color[i]=0;
color[s]=x;
q.push(s);
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    if(color[it]==1)
        x=-1;
    else
        x=1;
    for(i=0;i<v[it].size();i++)
        {
        //int y=(-1)*x;
        if(color[v[it][i]]==0)
            {
            color[v[it][i]]=x;
            q.push(v[it][i]);
            }
        else if(color[v[it][i]]==color[it])
            return 0;
        }
    }
return 1;
}

int main()
{
int n,i,j,a,b,m;
while(cin>>n&&n)
    {
    for(i=0;i<1000;i++)
        v[i].clear();
    cin>>m;
    for(i=1;i<=m;i++)
        {
        cin>>a>>b;
        if(i==1)
            s=a;
        v[a].push_back(b);
        v[b].push_back(a);
        }
    /*for(i=0;i<m;i++)
        {
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
        }*/
    int x;
    if(m>0)
        x=BFS();
    else
        x=1;
    if(x==1)
        cout<<"BICOLORABLE."<<endl;
    else
        cout<<"NOT BICOLORABLE."<<endl;
    q.empty();  s=0;
    }
return 0;
}
