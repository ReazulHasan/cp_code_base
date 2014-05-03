#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
using namespace std;

struct ss{
    int node1,node2;
    double cost;
};

class comp{
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
        };
};

/*class big{
    public:
    bool operator() (const ss &a,const ss &b){
            return a.cost<b.cost;
            }
};*/

priority_queue<ss,vector<ss>,comp> pq;
//priority_queue<ss,vector<ss>,big> res;
vector<ss> v;
int prev[500000],imp=0;

int find(int a)
{
imp++;
if(a==prev[a])
    return a;
return find(prev[a]);
}

int main()
{
int i,j,k,cas,sat,loc,x,y;
ss t;
cin>>cas;
while(cas--)
    {
    cin>>sat>>loc;
    for(i=0;i<loc;i++)
        {
        cin>>x>>y;
        for(j=0;j<i;j++)
            {
            int x1=v[j].node1;
            int y1=v[j].node2;
            t.node1=i+1;
            t.node2=j+1;
            t.cost=sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
            pq.push(t);
            }
        t.node1=x;
        t.node2=y;
        v.push_back(t);
        }
    for(i=0;i<=loc;i++)
        prev[i]=i;
    vector<double> res;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        x=t.node1;
        y=t.node2;
        imp=0;
        int bas1=find(x);
        int lo=imp;
        imp=0;
        int bas2=find(y);
        if(bas1!=bas2)
            {
            res.push_back(t.cost);
            if(lo>imp)
                prev[bas2]=bas1;
            else
                prev[bas1]=bas2;
            }
        //cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
        }
    sort(res.begin(),res.end(),greater<double>());
    sat--;
    double mn=res[sat];
    printf("%.2lf\n",mn);
    /*int sz=res.size();
    for(i=0;i<sz;i++)
        cout<<res[i]<<" ";*/
    v.clear(); res.clear();
    for(i=0;i<=loc;i++)
        prev[i]=0;
    }
return 0;
}
