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
int parent[3000000],imp=0;

int find(int m)
{
imp++;
if(parent[m]==m)
    return m;
return find(parent[m]);
}

int main()
{
int i,j,k,n,con,x,y,cab,cas,coun=0;
ss t;
cin>>cas;
while(cas--)
    {
    cin>>n;
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
        imp=0;
        int xroot=find(x);
        int lo=imp;
        imp=0;
        int yroot=find(y);
        if(xroot!=yroot)
            {
            if(lo>imp)
                parent[yroot]=xroot;
            else
                parent[xroot]=yroot;
            }
        }
    double res=0;
    int fl=0;
    if(coun)
        cout<<endl;
    coun=1;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        int r=t.node1;
        int s=t.node2;
        double c=t.cost;
        imp=0;
        int bas1=find(r);
        int lo=imp;
        imp=0;
        int bas2=find(s);
        if(bas1!=bas2)
            {
            fl=1;
            cout<<r<<" "<<s<<endl;
            res+=c;
            if(lo>imp)
                parent[bas2]=bas1;
            else
                parent[bas1]=bas2;
            }
        }
    if(fl==0)
        cout<<"No new highways need"<<endl;
    //printf("%.2lf\n",res);
    v.clear();
    for(i=0;i<=n;i++)
        parent[i]=0;
    }
return 0;
}
