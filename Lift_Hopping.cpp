#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct ss{
    int node;
    int cost;
    int lift;
};

class comp{
    int x;
    public:
        bool operator() (const ss &a, const ss &b){
            return a.cost>b.cost;
            }
    };

vector<ss> v[1500],star;
priority_queue<ss,vector<ss>,comp> pq;
int co[1000],no,dest;

void init()
{
int i,j;
for(i=0;i<1000;i++)
    co[i]=987654987;
co[0]=0;
}

int dijkstra()
{
int i,j,k;
ss t,d;
init();
vector<ss>::iterator it;
int ln=star.size();
int final=987654654,potaka=0;
for(i=0;i<ln;i++)
    {
    while(!pq.empty())
    pq.pop();
    t=star[i];
    pq.push(t);
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        if((t.node%100)==dest)
            {
            potaka=1;
            if(final>t.cost)
                final=t.cost;
            break;
            }
        for(it=v[t.node].begin();it!=v[t.node].end();it++)
            {
            int nod=it->node;
            int c=it->cost+t.cost;
            if(c<co[nod])
                {
                //cout<<"from node cost : "<<t.node<<" "<<nod<<" "<<c<<endl;
                //cout<<it->cost<<" "<<t.cost<<endl;
                co[nod]=c;
                d.node=nod;
                d.cost=c;
                d.lift=it->lift;
                pq.push(d);
                }
            }
        }
    }
if(potaka==0)
    return -1;
if(potaka==1)
    return final;
}

int main()
{
int cos[10],i,j,k;
vector<int> inp[10];
ss t;
while(cin>>no>>dest)
    {
    for(i=0;i<no;i++)
        cin>>cos[i];
    string s,sz;
    getline(cin,sz);
    int add=0;
    for(j=0;j<no;j++)
        {
        k=0;
        int flg=0,p;
        getline(cin,s);
        int len=s.size();
        for(i=0;i<len;)
            {
            int x=0,mu=0;
            while(s[i]!=' '&&i<len)
                {
                x*=10;
                x+=s[i]-'0';
                i++;
                mu=1;
                }
            inp[j].push_back(x+add);
            if(flg)
                {
                int imm=(x-p)*cos[j];
                t.node=x+add;
                t.cost=imm;
                t.lift=j;
                v[p+add].push_back(t);
                t.node=p+add;
                v[x+add].push_back(t);
                }
            p=x;
            flg=1;
            if(x==0&&mu==1)
                {
                ss t;
                t.node=x+add;
                t.cost=0;
                t.lift=j;
                star.push_back(t);
                }
            while(s[i]==' '&&i<len)
                i++;
            }
        add+=100;
        }
    int m,n;
    for(i=0;i<no;i++)
        {
        for(j=i;j<no;j++)
            {
            int ln=inp[j].size();
            for(k=0;k<ln;k++)
                {
                int it=inp[j][k];
                for(m=j+1;m<no;m++)
                    {
                    int hus=inp[m].size();
                    for(n=0;n<hus;n++)
                        {
                        int now=inp[m][n];
                        if((it%100)==(now%100))
                            {
                            t.node=it;
                            t.cost=60;
                            t.lift=j;
                            v[now].push_back(t);
                            t.node=now;
                            t.lift=m;
                            v[it].push_back(t);
                            }
                        }
                    }
                }
            }
        }
    int res=dijkstra();
    if(res==-1)
        cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<res<<endl;
    for(i=0;i<10;i++)
        {
        cos[i]=0;
        inp[i].clear();
        }
    for(i=0;i<1000;i++)
        v[i].clear();
    /*for(i=0;i<30;i++)
        {
        int ln=v[i].size();
        for(j=0;j<ln;j++)
            cout<<i<<" "<<v[i][j].node<<" "<<v[i][j].cost<<" "<<v[i][j].lift<<", ";
        cout<<endl;
        }
    for(i=0;i<star.size();i++)
        cout<<star[i].node<<" "<<star[i].cost<<" "<<star[i].lift<<endl;*/
    }
return 0;
}
