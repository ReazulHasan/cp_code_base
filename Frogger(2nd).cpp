#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cmath>
#include<algorithm>
using namespace std;

struct ss{
int nod;
double dis;
};

struct hm{
double stox,stoy;
};

vector<ss> v[5000];
vector<hm> vin;

class comp{
    int x;
    public:
    bool operator() (const ss &a, const ss &b)
        {
        return a.dis>b.dis;
        }
    };

priority_queue<ss,vector<ss>,comp> pq;
double inf=9999999,fin,mos[5000];
int num,color[5000];

double dijkstra()
{
int i,j,k;
ss t,d;
vector<ss>::iterator it;
while(!pq.empty())
    pq.pop();
t.nod=1;
t.dis=0;
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    //cout<<t.nod<<" nod : dis "<<t.dis<<endl;
    pq.pop();
    if(t.nod==2)
        return t.dis;
    color[t.nod]=1;
    for(it=v[t.nod].begin();it!=v[t.nod].end();it++)
        {
        int x=it->nod;
        double c=it->dis;
        //cout<<c<<" "<<t.dis<<" max: "<<max(c,t.dis)<<endl;
        if((mos[x]-max(c,t.dis))>0.00000001&&color[x]==0)
            {
            //cout<<"x: "<<x<<" ,c: "<<c<<endl;
            d.nod=x;
            if(c<t.dis)
                d.dis=t.dis;
            else
                d.dis=c;
            pq.push(d);
            }
        }
    }
return 0;
}

int main()
{
ss t;
hm d;
int i,j,k=0;
double x,y,dis,x1,y1;
d.stox=-1; d.stoy=-1;
while(cin>>num&&num)
    {
    k++;
    fin=-5;
    vin.clear();
    vin.push_back(d);
    for(i=0;i<=num;i++)
        {
        v[i].clear();
        mos[i]=inf;
        color[i]=0;
        }
    for(i=1;i<=num;i++)
        {
        cin>>x>>y;
        for(j=1;j<(i);j++)
            {
            d=vin[j];
            x1=d.stox; y1=d.stoy;
            dis=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
            t.nod=i; t.dis=dis;
            v[j].push_back(t);
            t.nod=j;
            v[i].push_back(t);
            }
        d.stox=x; d.stoy=y;
        vin.push_back(d);
        }
    /*for(i=1;i<=num;i++)
        {
        cout<<i<<": ";
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j].nod<<" ";
        cout<<endl;
        }*/
    double res=dijkstra();
    cout<<"Scenario #"<<k<<endl;
    printf("Frog Distance = %.3lf\n",res);
    cout<<endl;
    }
return 0;
}
