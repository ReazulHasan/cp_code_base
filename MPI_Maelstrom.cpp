#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int cos[1009];

struct ss{
int node;
int cost;
};

class comp{
int x;
public:
    bool operator() (const ss &a, const ss &b){
        return a.cost>b.cost;
        }
};

vector<ss> v[1009];
priority_queue<ss, vector<ss>, comp> pq;

int init()
{
int i;
for(i=0;i<1000;i++)
    cos[i]=214748400;
cos[0]=-200;
cos[1]=0;
while(!pq.empty())
    pq.pop();
return 0;
}

int dijkstra()
{
vector<ss>::iterator it;
ss t,d;
init();
int ver,c;
t.node=1;
t.cost=0;
pq.push(t);
while(!pq.empty())
    {
    t=pq.top();
    pq.pop();
    for(it=v[t.node].begin();it!=v[t.node].end();it++)
        {
        ver=it->node;
        c=it->cost+t.cost;
        if(c<cos[ver])
            {
            cos[ver]=c;
            d.node=ver;
            d.cost=c;
            pq.push(d);
            }
        }
    }
return 0;
}

int main()
{
char inp[1000][1000],zq[10];
/*for(i=0;i<105;i++)
    for(j=0;j<150;j++)
        inp[i][j]=' ';*/
ss t,d;
int i,j,n;
cin>>n;
gets(zq);
for(i=2;i<=n;i++)
    gets(inp[i]);
for(i=2;i<=n;i++)
    {
    int pos=0;
    int len=strlen(inp[i]);
    for(j=0;j<len;)
        {
        pos++;
        int now=0;
        if(inp[i][j]=='x')
            {
            j++;
            while(inp[i][j]==' '&&j<len)
                j++;
            }
        else
            {
            while(inp[i][j]!=' '&&j<len)
                {
                now*=10;
                now+=inp[i][j]-'0';
                j++;
                }
            while(inp[i][j]==' '&&j<len)
                j++;
            t.cost=now;
            t.node=i;
            v[pos].push_back(t);
            t.node=pos;
            v[i].push_back(t);
            //cout<<now<<" ";
            }
        }
    }
    dijkstra();
sort(cos,cos+(n+1));
    cout<<cos[n]<<endl;
/*for(i=1;i<=n;i++)
    {
    int len=v[i].size();
    for(j=0;j<len;j++)
        cout<<" from to cost"<<i<<" "<<v[i][j].node<<" "<<v[i][j].cost<<", ";
    cout<<endl;
    }*/
return 0;
}
