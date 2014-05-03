#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;

struct ss{
    int node1,node2;
    double cost;
};

struct hu{
    double nod1,nod2;
};

class comp{
    int x;
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
        };
};

priority_queue<ss,vector<ss>,comp> pq;
int parent[3000000];

int find(int a)
{
if(parent[a]==a)
    return a;
return find(parent[a]);
}

int main()
{
int cas,n,i,j,k,coun=0;
double x,y,x1,y1;
ss t;
hu h;
cin>>cas;
while(cas--)
    {
    vector<hu> v;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        for(j=0;j<i;j++)
            {
            t.node1=i+1;
            t.node2=j+1;
            x1=v[j].nod1;
            y1=v[j].nod2;
            t.cost=sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
            pq.push(t);
            }
        h.nod1=x; h.nod2=y;
        v.push_back(h);
        }
    for(i=1;i<=n;i++)
        parent[i]=i;
    double res=0;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        int p=t.node1;
        int q=t.node2;
        int m=find(p);
        int n=find(q);
        if(m!=n)
            {
            res+=t.cost;
            parent[m]=n;
            }
        }
    if(coun)
        cout<<endl;
    printf("%.2lf\n",res);
    v.clear();
    for(i=0;i<=n;i++)
        parent[i]=0;
    coun=1;
    /*while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
        }*/
    }
return 0;
}
