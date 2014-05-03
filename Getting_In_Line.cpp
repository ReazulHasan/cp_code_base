#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<deque>
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

priority_queue<ss,vector<ss>,comp> pq,pq1;
vector<ss> inp;
vector<int> v[1000];
int prev[1000],imp=0;

int check(int x)
{
imp++;
if(x==prev[x])
    return x;
return check(prev[x]);
}

int main()
{
int n,i,j,k,x,y,x1,y1,cas=0;
ss t;
double dist;
while(cin>>n&&n)
    {
    cas++;
    queue<int> q;
    int flag[1000],color[1000];
    for(i=0;i<n;i++)
        {
        cin>>x>>y;
        for(j=0;j<i;j++)
            {
            x1=inp[j].node1;
            y1=inp[j].node2;
            dist=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))+16.0;
            t.node1=i; t.node2=j; t.cost=dist;
            pq.push(t);
            pq1.push(t);
            }
        t.node1=x; t.node2=y; t.cost=i;
        inp.push_back(t);
        }
    double sum=0.0;
    for(i=0;i<=n;i++)
        {
        prev[i]=i;
        flag[i]=0;
        color[i]=0;
        v[i].clear();
        }
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        x=t.node1; y=t.node2;
        imp=0;
        int bas1=check(x);
        int hm=imp;
        imp=0;
        int bas2=check(y);
        if(bas1!=bas2&&flag[x]<2&&flag[y]<2)
            {
            flag[x]++; flag[y]++;
            sum+=t.cost;
            v[x].push_back(y);
            v[y].push_back(x);
            if(hm>imp)
                prev[bas2]=bas1;
            else
                prev[bas1]=bas2;
            //cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
            //cout<<inp[t.node1].node1<<" "<<inp[t.node1].node2<<" to "<<inp[t.node2].node1<<" "<<inp[t.node2].node2<<" "<<t.cost<<endl;
            }
        }
    //cout<<sum<<endl;
    int star;
    for(i=0;i<n;i++)
        if(flag[i]==1)
            {
            star=i;
            break;
            }
    cout<<"**********************************************************"<<endl;
    cout<<"Network #"<<cas<<endl;
    color[star]=1;
    q.push(star);
    while(!q.empty())
        {
        int now=q.front();
        q.pop();
        int len=v[now].size();
        for(i=0;i<len;i++)
            {
            int it=v[now][i];
            if(color[it]==0)
                {
                color[it]=1;
                x=inp[now].node1; y=inp[now].node2;
                x1=inp[it].node1; y1=inp[it].node2;
                dist=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))+16.0;
                cout<<"Cable requirement to connect ("<<x<<","<<y<<") to ("<<x1<<","<<y1<<") is ";
                printf("%.2lf feet.\n",dist);
                //cout<<now<<" "<<it<<endl;
                q.push(it);
                }
            }
        }
    printf("Number of feet of cable required is %.2lf.\n",sum);
    inp.clear();
    while(!pq1.empty())
        {
        t=pq1.top();
        pq1.pop();
        cout<<inp[t.node1].node1<<" "<<inp[t.node1].node2<<" to "<<inp[t.node2].node1<<" "<<inp[t.node2].node2<<" "<<t.cost<<endl;
        }
    }
return 0;
}
