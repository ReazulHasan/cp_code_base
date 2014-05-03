#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int no,edg,S,T,cost[50003];

struct ss{
int node;
int cost;
};

class comp{
int x;
public:
    bool operator() (const ss &a, const ss &b){
        return a.cost>b.cost;
    }
};

priority_queue< ss,vector<ss>, comp> pq;
vector<ss> v[50003];

void ini()
{
int i,j;
for(i=0;i<no;i++)
    cost[i]=21478000;
cost[S]=0;
}

int dijkstra()
{
ini();
vector<ss>::iterator it;
ss t,d;
int x,y;
t.node=S;
t.cost=0;
while(!pq.empty())
    pq.pop();
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    if(t.node==T) return t.cost;
    pq.pop();
    for(it=v[t.node].begin();it!=v[t.node].end();it++)
        {
        x=it->node;
        //y=it->cost;
        int c=it->cost+t.cost;
        if(c<cost[x])
            {
            //cout<<"x y cost"<<t.node<<" "<<x<<" "<<c<<endl;
            cost[x]=c;
            d.cost=c;
            d.node=x;
            pq.push(d);
            }
        }
    }
return -1;
}

int main()
{
ss t,d;
int x,y,n,i,j,c,coun=0;
cin>>n;
while(n--)
    {
    coun++;
    cin>>no>>edg>>S>>T;
    for(i=0;i<no;i++)
        v[i].clear();
    for(i=0;i<edg;i++)
        {
        cin>>x>>y>>c;
        t.node=x;
        t.cost=c;
        v[y].push_back(t);
        t.node=y;
        v[x].push_back(t);
        }
    cout<<"Case #"<<coun<<": ";
    int res=dijkstra();
    if(edg==0||res==-1)
        cout<<"unreachable"<<endl;
    else
        cout<<res<<endl;
/*    for(i=0;i<no;i++)
        cout<<i<<" : "<<cost[i]<<" ";*/
    /*for(i=0;i<no;i++)
        {
        int len=v[i].size();
        for(j=0;j<len;j++)
            {
            t=v[i][j];
            cout<<"node cost : "<<t.node<<" "<<t.cost<<" ";
            }
        cout<<endl;
        }*/
    }
return 0;
}
