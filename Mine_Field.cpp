#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;

double inf=98798798;

struct ss{
    int node;
    double cost;
    };

struct sr{
    double node1,node2;
    };

class comp{
    public:
    bool operator() (const ss &a,const ss &b){
            return a.cost>b.cost;
            };
};

priority_queue<ss,vector<ss>,comp> pq;
vector<ss> vec[30000];
double khor[30000];

int ini(int m)
{
int i;
for(i=0;i<=m;i++)
    khor[i]=inf;
}

double dijkstra(int S,int D)
{
ss t,d;
vector<ss>::iterator it;
int i,j,k,v;
double c;
ini(D);
khor[S]=0;
t.node=S;
t.cost=0;
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    pq.pop();
    if(t.node==D)
        return t.cost;
    for(it=vec[t.node].begin();it!=vec[t.node].end();it++)
        {
        v=it->node;
        if((it->cost)<=1.5)
            {
            c=it->cost+t.cost;
            if(c<khor[v])
                {
                khor[v]=c;
                d.cost=c;
                d.node=v;
                pq.push(d);
                }
            }
        }
    }
return -1;
}

int main()
{
int i,j,k,co,ro,n;
double x,y,x1,y1;
string s;
while(cin>>s)
    {
    ss t;
    sr d;
    vector<sr> v;
    if(s[0]=='*')
        break;
    cin>>co;
    ro=0;
    int len=s.size();
    for(i=0;i<len;i++)
        {
        ro*=10;
        ro+=s[i]-'0';
        }
    d.node1=0.0; d.node2=0.0;
    v.push_back(d);
    cin>>n;
    for(i=1;i<=(n+1);i++)
        {
        if(i==n+1)
            {
            x=ro; y=co;
            }
        else
            cin>>x>>y;
        for(j=0;j<i;j++)
            {
            x1=v[j].node1;
            y1=v[j].node2;
            double dis=sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
            t.node=i; t.cost=dis;
            if(dis<=1.5)
                vec[j].push_back(t);
            }
        d.node1=x; d.node2=y;
        v.push_back(d);
        }
    double tot;
    cin>>tot;
    double res=dijkstra(0,n+1);
    if(res==-1||res>tot)
        cout<<"Boom!"<<endl;
    else
        cout<<"I am lucky!"<<endl;
    for(i=0;i<=(n+1);i++)
        vec[i].clear();
    //cout<<res<<endl;
    }
return 0;
}
