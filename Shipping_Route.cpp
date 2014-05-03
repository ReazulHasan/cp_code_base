#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

vector<int> v[1000];
typedef map<string,int>maps;
maps mp;

int BFS(int s,int d)
{
int i,j,color[100],cost[100],now;
queue<int> q;
q.push(s);
for(i=0;i<100;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
color[s]=1;
while(!q.empty())
    {
    now=q.front();
    q.pop();
    if(now==d)
        return cost[d];
    for(i=0;i<v[now].size();i++)
        {
        if(color[v[now][i]]==0)
            {
            color[v[now][i]]=1;
            cost[v[now][i]]=cost[now]+1;
            q.push(v[now][i]);
            }
        }
    }
return -1;
}


int main()
{
maps::iterator it;
string s,s1,s2;
int i,j,k,l,t,node,edg,req;
cin>>t;
cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
for(l=1;l<=t;l++)
    {
    for(k=0;k<1000;k++)
        v[k].clear();
    int ind=0;
    cin>>node>>edg>>req;
    cout<<"DATA SET  "<<l<<endl<<endl;
    for(k=0;k<node;k++)
        {
        cin>>s;
        mp[s]=ind++;
        }
    for(k=0;k<edg;k++)
        {
        cin>>s1>>s2;
        //cout<<mp[s1]<<" "<<mp[s2]<<endl;
        v[mp[s1]].push_back(mp[s2]);
        v[mp[s2]].push_back(mp[s1]);
        }
    for(k=0;k<req;k++)
        {
        int c,res,d,s;
        string a,b;
        cin>>c>>a>>b;
        s=mp[a];
        d=mp[b];
        res=BFS(s,d);
        if(res>-1)
            cout<<"$"<<100*res*c<<endl;
        else
            cout<<"NO SHIPMENT POSSIBLE"<<endl;
        }
    cout<<endl;
    }
cout<<"END OF OUTPUT"<<endl;
return 0;
}
