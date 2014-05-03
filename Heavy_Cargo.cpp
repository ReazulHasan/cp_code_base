#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<map>
using namespace std;

struct ss{
    int node1,node2,cost;
};

class comp{
    int x;
    public:
    bool operator() (const ss &a,const ss &b){
        return a.cost<b.cost;
    };
};

priority_queue<ss,vector<ss>,comp> pq;
int prev[2000000],imp=0;

int find(int a)
{
imp++;
if(a==prev[a])
    return a;
return find(prev[a]);
}

vector<int> v[500];
int ar[500][500],color[500],star,en,fin[500],cos[500];

int BFS()
{
int i,j,k;
queue<int> q;
q.push(star);
color[star]=1;
cos[star]=0;
int flag=0,cou=0;
while(!q.empty())
    {
    int x=q.front();
    q.pop();
    if(x==en)
        return fin[x];
   /* if(x==star)
        {
        if(flag==2)
            return fin[x];
        flag=1;
        }
    if(x==en)
        {
        if(flag==1)
            return fin[x];
        flag=2;
        }*/
    int len=v[x].size();
    for(i=0;i<len;i++)
        {
        int now=v[x][i];
        if(color[now]==0)
            {
            color[now]=1;
            fin[now]=ar[x][now];
            if(cou)
            if(fin[now]>fin[x])
                fin[now]=fin[x];
            q.push(now);
            }
        }
    cou++;
    }
}

int main()
{
int i,j,k,city,road,c,kas=0;
string s1,s2;
while(cin>>city>>road)
    {
    kas++;
    ss t;
    int pos=1,x,y;
    map<string,int> mpstr;
    map<int,string> mpint;
    if(city==0&&road==0)
        break;
    for(i=0;i<road;i++)
        {
        cin>>s1>>s2>>c;
        if(mpstr[s1]==0)
            {
            mpstr[s1]=pos;
            mpint[pos]=s1;
            x=pos;
            pos++;
            }
        else
            x=mpstr[s1];
        if(mpstr[s2]==0)
            {
            mpstr[s2]=pos;
            mpint[pos]=s2;
            y=pos;
            pos++;
            }
        else
            y=mpstr[s2];
        t.node1=x;
        t.node2=y;
        t.cost=c;
        pq.push(t);
        }
    for(i=1;i<=city;i++)
        prev[i]=i;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        x=t.node1;
        y=t.node2;
        imp=0;
        int che1=find(x);
        int lo=imp;
        imp=0;
        int che2=find(y);
        if(che1!=che2)
            {
            //cout<<x<<" "<<y<<" "<<t.cost<<endl;
            v[x].push_back(y);
            v[y].push_back(x);
            ar[x][y]=t.cost;
            ar[y][x]=t.cost;
            if(lo>imp)
                prev[che2]=che1;
            else
                prev[che1]=che2;
            }
        //cout<<t.node1<<" "<<t.node2<<" "<<t.cost<<endl;
        }
    cin>>s1>>s2;
    star=mpstr[s1];
    en=mpstr[s2];
    if(star>en)
        {
        int temp=star;
        star=en;
        en=temp;
        }
    for(i=0;i<=city;i++)
        fin[i]=30000;
    int oh=BFS();
    cout<<"Scenario #"<<kas<<endl;
    cout<<oh<<" tons"<<endl<<endl;
    for(i=0;i<=city;i++)
        for(j=0;j<=city;j++)
            {
            ar[i][j]=0;
            fin[i]=0;
            color[i]=0;
            prev[i]=0;
            v[i].clear();
            }
    mpstr.clear(); mpint.clear();
    s1.clear(); s2.clear();
    }
return 0;
}
