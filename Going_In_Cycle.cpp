#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;

struct ss{
 int u,v;
};

vector<int> vs[1000],vt[1000],vinp;
vector<ss> edg;
map<int,int> mp;
int cost[1000][1000],colors[1000],colort[1000];
stack<int> st;

int DFS(int x)
{
int i,j,k;
colors[x]=1;
int len=vs[x].size();
for(i=0;i<len;i++)
    {
    int it=vs[x][i];
    if(colors[it]==0)
        DFS(it);
    }
st.push(x);
return 0;
}

int coun=0,sum=0,fin,start;

int visit(int x)
{
ss t,d;
int i,j,k;
if(coun>0&&start==x)
    return 0;
coun++;
//colort[x]=1;
int len=vt[x].size();
for(i=0;i<len;i++)
    {
    int it=vt[x][i];
    if(colort[it]==0)
        {
        fin=it;
        t.u=x; d.u=it;
        t.v=it; d.v=x;
        //cout<<"x it "<<x<<" "<<it<<endl;
        //edg.push_back(t);
        edg.push_back(d);
        sum+=cost[it][x];
        visit(it);
        }
    }
return 0;
}

int main()
{
int t,node,edge,i,j,k;
cin>>t;
while(t--)
    {
    cin>>node>>edge;
    vinp.clear(); mp.clear();
    while(!st.empty())
        st.pop();
    for(i=0;i<=node;i++)
        {
        vs[i].clear();
        vt[i].clear();
        for(j=0;j<=node;j++)
            {
            cost[i][j]=0;
            colors[i]=0;
            colort[i]=0;
            }
        }
    int u,v,c;
    for(i=0;i<edge;i++)
        {
        cin>>u>>v>>c;
        vs[u].push_back(v);
        vt[v].push_back(u);
        cost[u][v]=c;
        if(mp[u]==0)
            {
            mp[u]=1;
            vinp.push_back(u);
            }
        if(mp[v]==0)
            {
            mp[v]=1;
            vinp.push_back(v);
            }
        }
    int len=vinp.size();
    for(i=0;i<len;i++)
        {
        int it=vinp[i];
        if(colors[it]==0)
            DFS(it);
        }
    double min=987654321;
    while(!st.empty())
        {
        int now=st.top();
        st.pop();
        if(colort[now]==0)
            {
            start=now;
            edg.clear();
            coun=0; sum=0;
            visit(now);
            }
        int ln=edg.size();
        if(ln==0)
            colort[now]=1;
        int tot=0,hum=0;
        for(i=0;i<ln;i++)
            {
            ss t;
            t=edg[i];
            int x=t.u;
            int y=t.v;
            if(cost[x][y]!=0)
                {
                tot++;
                hum+=cost[x][y];
                }
            colort[x]=1;
            colort[y]=1;
            }
        double hi=hum*1.0;
        double fi=tot*1.0;
        double fuki=hi/fi;
        if(min>fuki)
            min=fuki;
        }
    printf("%.2lf\n",min);
    }
return 0;
}
