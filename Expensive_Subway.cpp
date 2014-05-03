#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<deque>
using namespace std;

struct ss{
int nod1,nod2,cost;
};

class comp{
int x;
public:
    bool operator() (const ss &a,const ss &b){
        return a.cost>b.cost;
        };
};

priority_queue<ss,vector<ss>,comp> pq;
int root[1000],hm=0,color[1000],con=1;
vector<int> v[1000];
queue<int> q;

int find_root(int x)
{
hm++;
if(x==root[x])
    return x;
else
    return find_root(root[x]);
}

int BFS(int star)
{
int i,j,k;
color[star]=1;
q.push(star);
while(!q.empty())
    {
    int x=q.front();
    q.pop();
    int len=v[x].size();
    for(i=0;i<len;i++)
        {
        int it=v[x][i];
        if(color[it]==0)
            {
            color[it]=1;
            con++;
            q.push(it);
            }
        }
    }
return 0;
}

int main()
{
int station,road,i,j,k,c;
string s1,s2;
ss t;
while(cin>>station>>road)
    {
    map<string,int> mpstr;
    map<int,string> mpint;
    if(station==0&&road==0)
        break;
    for(i=0;i<station;i++)
        {
        cin>>s1;
        mpstr[s1]=i+1;
        mpint[i+1]=s1;
        }
    for(i=0;i<road;i++)
        {
        cin>>s1>>s2>>c;
        t.nod1=mpstr[s1];
        t.nod2=mpstr[s2];
        t.cost=c;
        pq.push(t);
        }
    for(i=1;i<=station;i++)
        root[i]=i;
    int coun=0,res=0;
    while(!pq.empty())
        {
        t=pq.top();
        pq.pop();
        int hm=0;
        int bas1=find_root(t.nod1);
        int len1=hm;
        hm=0;
        int bas2=find_root(t.nod2);
        if(bas1!=bas2)
            {
            v[t.nod1].push_back(t.nod2);
            v[t.nod2].push_back(t.nod1);
            res+=t.cost;
            if(len1>hm)
                root[bas2]=bas1;
            else
                root[bas1]=bas2;
            }
        //cout<<t.nod1<<" "<<t.nod2<<" "<<t.cost<<endl;
        }
    cin>>s1;
    con=1;
    int check=BFS(mpstr[s1]);
    if(con==station)
        cout<<res<<endl;
    else
        cout<<"Impossible"<<endl;
    mpstr.clear(); mpint.clear();
    s1.clear(); s2.clear();
    for(i=0;i<=station;i++)
        {
        root[i]=0;
        v[i].clear();
        color[i]=0;
        }
    }
return 0;
}
