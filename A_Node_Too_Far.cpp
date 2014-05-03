//Bismillah
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

vector<int> v[10000];
map<string,int>mp;
int s,d,cost[10000];

int BFS()
{
queue<int>q;
int i,j,color[10000],coun=1;
for(i=0;i<10000;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
color[s]=1;
cost[s]=0;
q.push(s);
while(!q.empty())
    {
    int nw=q.front();
    q.pop();
    for(i=0;i<v[nw].size();i++)
        {
        if(color[v[nw][i]]==0)
            {
            color[v[nw][i]]=1;
            cost[v[nw][i]]=cost[nw]+1;
            if(cost[v[nw][i]]<=d)
                coun++;
            q.push(v[nw][i]);
            }
        }
    }
return coun;
}

int main()
{
string a,b,e;
int n,cn=0,f;
while(cin>>n)
    {
    for(int i=0;i<10000;i++)
        v[i].clear();
    if(n==0)
        break;
    int x=1;
    for(int i=0;i<n;i++)
        {
        cin>>a>>b;
        if(mp[a]==0)
            {
            mp[a]=x;
            x++;
            }
        if(mp[b]==0)
            {
            mp[b]=x;
            x++;
            }
        v[mp[a]].push_back(mp[b]);
        v[mp[b]].push_back(mp[a]);
        }
    int rs=mp.size();
    //cout<<rs<<endl;
    string c("0");
    while(cin>>e>>d)
        {
        if(e==c&&d==0)
            break;
        s=mp[e];
        cn++;
        //cout<<mp.size()<<endl;
        int res=BFS();
        res=rs-res;
        cout<<"Case "<<cn<<": "<<res<<" nodes not reachable from node "<<e<<" with TTL = "<<d<<"."<<endl;
        }
    mp.clear();
    }
return 0;
}
