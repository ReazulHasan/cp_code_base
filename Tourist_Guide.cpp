#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> v[1000];
vector<int> art;
vector<string> res;
int prev[1000],child[1000],color[1000],dis[1000],lo[1000],t=1,star=0;
map<int,int> mp;

int DFS(int x)
{
int i,j,k;
color[x]=1;
dis[x]=t;
lo[x]=t;
t++;
int len=v[x].size();
for(i=0;i<len;i++)
    {
    int y=v[x][i];
    if(color[y]==0)
        {
        prev[y]=x;
        child[x]++;
        DFS(y);
        if(lo[y]>=dis[x]&&prev[y]!=-1&&mp[x]==0&&x!=star)
            {
            mp[x]=1;
            art.push_back(x);
            }
        lo[x]=min(lo[x],lo[y]);
        }
    else
        lo[x]=min(lo[x],dis[y]);
    }
return 0;
}

int main()
{
int i,j,k,n,kas=0;
string s,s1,s2;
while(cin>>n&&n)
    {
    kas++;
    int t=1,cas;
    map<string,int> mpstr;
    map<int,string> mpint;
    for(i=1;i<=n;i++)
        {
        cin>>s;
        mpstr[s]=t;
        mpint[t]=s;
        t++;
        }
    cin>>cas;
    while(cas--)
        {
        cin>>s1>>s2;
        int x,y;
        x=mpstr[s1];
        y=mpstr[s2];
        v[x].push_back(y);
        v[y].push_back(x);
        }
    /*for(i=1;i<=n;i++)
        {
        int len=v[i].size();
        for(j=0;j<len;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
        }*/
    for(i=1;i<=n;i++)
        if(color[i]==0)
            {
            t=1;
            prev[i]=-1;
            star=i;
            DFS(i);
            if(child[i]>1)
                art.push_back(i);
            }
    int ln=art.size();
    if(kas>1)
        cout<<endl;
    cout<<"City map #"<<kas<<": "<<ln<<" camera(s) found"<<endl;
    for(i=0;i<ln;i++)
        res.push_back(mpint[art[i]]);
    sort(res.begin(),res.end());
    for(i=0;i<ln;i++)
        cout<<res[i]<<endl;
    for(i=0;i<=n;i++)
        {
        v[i].clear();
        color[i]=0;
        child[i]=0;
        prev[i]=0;
        dis[i]=0;
        lo[i]=0;
        }
    mpstr.clear(); mpint.clear(); mp.clear();
    star=0; art.clear(); res.clear();
    }
return 0;
}
