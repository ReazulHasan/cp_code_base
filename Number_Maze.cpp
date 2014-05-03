#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;

char inp[3000][5000],zq[5];
int in[5500][5500];
int dir1[]={-1,0,0,1};
int dir2[]={0,-1,1,0};
int cos[1500000];

struct ss{
int node;
int cost;
};

class comp{
int x;
public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
    }
};

priority_queue<ss,vector<ss>,comp> pq;
vector<ss> v[1900000];

int init()
{
int i,j;
for(i=0;i<1200;i++)
    cos[i]=535987463;
cos[0]=0;
while(!pq.empty())
    pq.pop();
return 0;
}

int dijkstra()
{
vector<ss>::iterator it;
init();
ss t,d;
int no,c;
t.node=0;
t.cost=0;
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    pq.pop();
    for(it=v[t.node].begin();it!=v[t.node].end();it++)
        {
        no=it->node;
        c=it->cost+t.cost;
        if(c<cos[no])
            {
            //cout<<t.node<<" "<<no<<" "<<c<<endl;
            cos[no]=c;
            d.node=no;
            d.cost=c;
            pq.push(d);
            }
        }
    }
return 0;
}

int main()
{
ss t,d;
int cas,ro,co,i,j,k;
cin>>cas;
while(cas--)
    {
    for(i=0;i<1500;i++)
        v[i].clear();
    cin>>ro>>co;
    gets(zq);
    for(i=0;i<ro;i++)
        gets(inp[i]);
    for(i=0;i<ro;i++)
        {
        int po=0;
        int len=strlen(inp[i]);
        for(j=0;j<len;j++)
            if(inp[i][j]!=' ')
                in[i][po++]=inp[i][j]-'0';  //storing values removing spaces
        }
    for(i=0;i<ro;i++)
        {
        for(j=0;j<co;j++)
            {
            for(k=0;k<4;k++)
                {
                int x=i+dir1[k];
                int y=j+dir2[k];
                if(x>=0&&x<ro&&y>=0&&y<co)
                    {
                    int no1=i*co+j;  //transforming each cell with corresponding row column
                    int no2=x*co+y;  //to a unique value.
                    t.node=no1;
                    t.cost=in[i][j];
                    v[no2].push_back(t);
                    }
                }
            }
        }
    dijkstra();
    int xy=(ro*co)-1;  //final cell value is calculated by ro*co-1.
    cout<<(cos[xy]+in[0][0])<<endl;
    /*for(i=0;i<ro;i++)
        {
        int ln=v[i].size();
        for(j=0;j<ln;j++)
            cout<<i<<" "<<v[i][j].node<<" "<<v[i][j].cost<<", ";
        cout<<endl;
        }*/
    }
return 0;
}
