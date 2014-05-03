#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct ss{
    int node1,node2,cost;
};

class comp{
    int x;
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
        };
};

priority_queue<ss,vector<ss>,comp> pq;
vector<int> v[200];
int cos[200][200],parent[200],imp=0,color[200],fin[200];

int find(int a)
{
imp++;
if(parent[a]==a)
    return a;
return find(parent[a]);
}

int BFS(int star,int en)
{
int i,j,k;
queue<int> q;
q.push(star);
color[star]=1;
int fl=0;
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    if(it==en)
        return fin[it];
    int len=v[it].size();
    for(i=0;i<len;i++)
        {
        int now=v[it][i];
        if(color[now]==0)
            {
            //cout<<it<<" "<<now<<endl;
            color[now]=1;
            fin[now]=cos[it][now];
            if(fl)
            if(fin[now]<fin[it])
                fin[now]=fin[it];
            q.push(now);
            }
        }
    fl=1;
    }
return -1;
}

int main()
{
int i,j,k,cross,road,quer,x,y,c,coun=0;
ss t;
while(cin>>cross>>road>>quer)
    {
    if(cross==0&&road==0&&quer==0)
        break;
    coun++;
    for(i=1;i<=road;i++)
        {
        cin>>x>>y>>c;
        t.node1=x;
        t.node2=y;
        t.cost=c;
        pq.push(t);
        }
    for(i=1;i<=100;i++)
        parent[i]=i;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        x=t.node1; y=t.node2;
        imp=0;
        int bas1=find(x);
        int lo=imp;
        int bas2=find(y);
        if(bas1!=bas2)
            {
            cos[x][y]=t.cost;
            cos[y][x]=t.cost;
            v[x].push_back(y);
            v[y].push_back(x);
            //cout<<x<<" "<<y<<" "<<t.cost<<endl;
            if(lo>imp)
                parent[bas2]=bas1;
            else
                parent[bas1]=bas2;
            }
        //cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
        }
    if(coun>1)
        cout<<endl;
    cout<<"Case #"<<coun<<endl;
    for(i=1;i<=quer;i++)
        {
        cin>>x>>y;
        int res=BFS(x,y);
        if(res==-1)
            cout<<"no path"<<endl;
        else
            cout<<res<<endl;
        for(j=0;j<=cross;j++)
            {
            color[j]=0;
            fin[j]=0;
            }
        }
    for(i=0;i<=cross;i++)
        {
        for(j=0;j<=cross;j++)
            {
            cos[i][j]=0;
            }
        parent[i]=0;
        color[i]=0;
        fin[i]=0;
        v[i].clear();
        }
    imp=0;
    }
return 0;
}
