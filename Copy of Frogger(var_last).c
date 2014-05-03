#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cmath>
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
    bool operator() (const ss &a,const ss &b)
        {
        return a.dis>b.dis;
        };
    };

priority_queue<ss,vector<ss>,comp> pq,last;
double mos[99999],inf=9999999,fin;
int num,prev[99999];

double dijkstra()
{
ss t,d;
vector<ss>::iterator it;
t.nod=1;
t.dis=0;
pq.push(t)
double maxn=-5,minx=21494789;
while(!pq.empty())
    {
    int g; double h;
    t=pq.front();
    pq.pop();
    if(maxn<t.dis)
        maxn=t.dis;
    if(t.nod==2)
        return maxn;
    int mu=t.nod;
    int mn=24948697;
    for(it=v[mu].begin();it!=v[mu].end();it++)
        {
        int ogo=it->nod;
        int co=it->dis;
        if(minx>co)
            {
            g=ogo;
            h=co;
            }
        }
    d.nod=g; d.dis=h;
    pq.push(d);
    }
}


int main()
{
ss t;
hm d;
int i,j,k;
double x,y,dis,x1,y1;
d.stox=-1; d.stoy=-1;
while(cin>>num&&num)
    {
    double a[500][500];
    fin=-5;
    vin.clear();
    vin.push_back(d);
    for(i=0;i<=num;i++)
        {
        v[i].clear();
        prev[i]=0;
        mos[i]=inf;
        for(j=0;j<=num;j++)
            a[i][j]=0;
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
            a[i][j]=dis;
            a[j][i]=dis;
            }
        d.stox=x; d.stoy=y;
        vin.push_back(d);
        }
    double res=dijkstra();
    //cout<<res<<endl;
    double minx=9999999;
    int m=2,n;
    while(prev[m]!=-1)
        {
        n=prev[m];
        if(minx>a[m][n])
            minx=a[m][n];
        m=n;
        }
    cout<<minx<<endl;
    }
return 0;
}
