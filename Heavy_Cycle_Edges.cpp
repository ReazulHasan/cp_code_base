#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

struct ss{
    int u,v,cos;
    };

int prev[20000],coun=0;;

/*bool comp(ss a,ss b)
{
return a.cos>b.cos;
};*/
class comp{
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cos>b.cos;
        };
};


priority_queue<ss,vector<ss>,comp> pq;

int find(int x)
{
coun++;
if(x==prev[x])
    return x;
return find(prev[x]);
}

int main()
{
int i,j,k,nod,edg,x,y,c;
ss t;
while(cin>>nod>>edg)
    {
    if(!nod&&!edg)
        break;
    for(i=0;i<edg;i++)
        {
        cin>>x>>y>>c;
        t.u=x; t.v=y; t.cos=c;
        pq.push(t);
        }
    for(i=0;i<nod;i++)
        prev[i]=i;
    vector<int> res;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        x=t.u;
        y=t.v;
        int imp1=0,imp2=0,bas1,bas2;
        coun=0;
        bas1=find(x);
        imp1=coun;
        coun=0;
        bas2=find(y);
        imp2=coun;
        if(bas1!=bas2)
            {
            if(imp1>imp2)
                prev[bas2]=bas1;
            else
                prev[bas1]=bas2;
            }
        else
            res.push_back(t.cos);
        //cout<<t.cos<<endl;
        }
    sort(res.begin(),res.end());
    int len=res.size();
    if(len>0)
        {
        cout<<res[0];
        for(i=1;i<len;i++)
            cout<<" "<<res[i];
        cout<<endl;
        }
    else
        cout<<"forest"<<endl;
    }
return 0;
}
