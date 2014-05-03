#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<cmath>
using namespace std;

struct ss{
    int node1,node2;
    double cost;
};

class comp{
    int x;
    public:
        bool operator() (const ss &a,const ss &b){
            return a.cost>b.cost;
            };
    };

vector<ss> v;
priority_queue<ss,vector<ss>,comp> pq;
int parent[3000000];

int find(int m)
{
if(parent[m]==m)
    return m;
return find(parent[m]);
}

int main()
{
int i,j,k,n,con,x,y,cab;
ss t;
while(cin>>n)
    {
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        for(j=0;j<i;j++)
            {
            int x1,y1;
            x1=v[j].node1;
            y1=v[j].node2;
            t.node1=i+1;
            t.node2=j+1;
            t.cost=sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
            pq.push(t);
            }
        t.node1=x; t.node2=y;
        v.push_back(t);
        }
    for(i=1;i<=n;i++)
        parent[i]=i;
    cin>>cab;
    for(i=1;i<=cab;i++)
        {
        cin>>x>>y;
        int xroot=find(x);
        int yroot=find(y);
        if(xroot!=yroot)
            parent[xroot]=yroot;
        }
    double res=0;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        int r=t.node1;
        int s=t.node2;
        double c=t.cost;
        int bas1=find(r);
        int bas2=find(s);
        if(bas1!=bas2)
            {
            res+=c;
            parent[bas1]=bas2;
            }
        }
    printf("%.2lf\n",res);
    v.clear();
    for(i=0;i<=n;i++)
        parent[i]=0;
    }
return 0;
}
