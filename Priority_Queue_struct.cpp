#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct ss{
int node1,node2,cost;
};

struct mark{
    int no,par;
    };

class fuki{
    //int x;
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
    }
};

priority_queue<ss,vector<ss>,fuki> pq;

int main()
{
int i,j,k,n,e,x,y,c;
ss t;
mark d;
cin>>n>>e;
for(i=1;i<=n;i++)

for(i=0;i<e;i++)
    {
    cin>>x>>y>>c;
    t.node1=x;
    t.node2=y;
    t.cost=c;
    pq.push(t);
    }
while(!pq.empty())
    {
    t=pq.top();
    pq.pop();
    cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
    }
return 0;
}
