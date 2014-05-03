#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

struct ss{
    int node;
    int cost;
};

class comp{
int x;
public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
    }
};

vector<ss> v[5000];
priority_queue<ss,vector<ss>,comp> pq;
map<int,int> mp;
int sorce,dest;
int color[5000],prev[5000],cos[5000];

void init()
{
int i,j;
for(i=0;i<3000;i++)
    cos[i]=98765432;
while(!pq.empty())
    pq.pop();
}

int dijkstra()
{
init();
vector<ss>::iterator it;
int i,j,k;
ss t,d;
t.node=sorce;
if(mp[sorce]==0)
    t.cost=1;
else
    t.cost=0;
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    if(t.node==dest) return t.cost;
    //cout<<t.node<<" "<<t.cost<<endl;
    pq.pop();
    for(it=v[t.node].begin();it!=v[t.node].end();it++)
        {
        int no=it->node;
        int c=it->cost+t.cost;
        //cout<<t.cost<<" "<<it->cost<<endl;
        if(c<cos[no])
            {
            cos[no]=c;
            d.node=no;
            d.cost=c;
            pq.push(d);
            }
        }
    }
return -1;
}

int main()
{
int i,j,k,l,cas,city,rut,air;
ss t,d;
cin>>cas;
for(l=1;l<=cas;l++)
    {
    mp.clear();
    for(i=0;i<4000;i++)
        v[i].clear();
    cin>>city>>rut>>air;
    for(i=1;i<=air;i++)
        {
        int x;
        cin>>x;
        mp[x]=1;
        }
    for(i=1;i<=rut;i++)
        {
        int x,y;
        cin>>x>>y;
        t.node=y;
        if(mp[y]==0)
            t.cost=1;
        else
            t.cost=0;
        v[x].push_back(t);
        t.node=x;
        if(mp[x]==0)
            t.cost=1;
        else
            t.cost=0;
        v[y].push_back(t);
        }
    /*for(i=1;i<=city;i++)
        {
        cout<<i<<" ";
        int len=v[i].size();
        for(j=0;j<len;j++)
            cout<<"node cost "<<v[i][j].node<<" "<<v[i][j].cost<<" ";
        cout<<endl;
        }*/
    int q;
    cin>>q;
    cout<<"Case "<<l<<":"<<endl;
    for(i=1;i<=q;i++)
        {
        cin>>sorce>>dest;
        if(sorce==dest)
            cout<<"0"<<endl;
        else
            {
            int res=dijkstra();
            cout<<res<<endl;
            }
        }
    //if(l<cas)
        cout<<endl;
    }
//cout<<"orthi";
return 0;
}
