                //Bismillahir Rahmanir Rahim
                //My first code for Dijkstra
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<list>
using namespace std;

int S,T,price[100];

struct str
{
int node;
int cost;
};

class comp{
    int x;
    public:
        bool operator() (const str &a, const str &b){
            return a.cost>b.cost;
            }
    };

priority_queue<str,vector<str>, comp> pq;
list<str> lis[100];

int dijkstra()
{
int i,j,k;
for(i=0;i<100;i++)
    price[i]=12345;
price[S]=0;
list<str>::iterator it;
int v,c;
str t,d;
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
    for(it=lis[t.node].begin();it!=lis[t.node].end();it++)
        {
        v=it->node;
        c=it->cost+t.cost;
        cout<<"v c "<<v<<" "<<c<<endl;
        if(c<price[v])
            {
            price[v]=c;
            d.cost=c;
            d.node=v;
            pq.push(d);
            }
        }
    }
}

int main()
{
int i,j,k,ver,edg,cos;
str stvar;
cin>>ver>>edg>>S>>T;
for(i=0;i<edg;i++)
    {
    int x,y;
    cin>>x>>y>>cos;
    stvar.cost=cos;
    stvar.node=y;
    lis[x].push_back(stvar);
    stvar.node=x;
    lis[y].push_back(stvar);
    }
/*    for(i=1;i<=ver;i++)
        cout<<lis[i].stvar.node<<" "<<lis[i].stvar.cost<<endl;*/
    int res;
    if(edg>0)
        res=dijkstra();
    cout<<res<<endl;
return 0;
}
