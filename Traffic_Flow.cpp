#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

struct ss{
    int node1,node2,cost;
};

class comp{
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost<b.cost;
        };
};

priority_queue<ss,vector<ss>,comp> pq;

int imp=0,prev[100000];

int find(int a)
{
imp++;
if(a==prev[a])
    return a;
return find(prev[a]);
}

int main()
{
int i,j,k,cas,ct,road,x,y,coun=0,c;
ss t;
cin>>cas;
while(cas--)
    {
    coun++;
    vector<int> v;
    cin>>ct>>road;
    for(i=0;i<road;i++)
        {
        cin>>x>>y>>c;
        if(x!=y)
            {
            //cout<<"here"<<endl;
            t.node1=x;
            t.node2=y;
            t.cost=c;
            pq.push(t);
            }
        }
    for(i=0;i<ct;i++)
        prev[i]=i;
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
            v.push_back(t.cost);
            if(lo>imp)
                prev[bas2]=bas1;
            else
                prev[bas1]=bas2;
            }
        }
        sort(v.begin(),v.end());
        //cout<<v.size()<<endl;
        cout<<"Case #"<<coun<<": "<<v[0]<<endl;
        for(i=0;i<ct;i++)
            {
            prev[i]=0;
            }
        v.clear();
        //cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
    }
return 0;
}
