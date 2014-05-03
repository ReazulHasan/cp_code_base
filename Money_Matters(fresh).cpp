#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;

vector<int> v[20000];
int sum=0,a[20000],color[20000];

int dfs(int x)
{
int i,j,k;
color[x]=1;
//cout<<x<<endl;
sum+=a[x];
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        dfs(v[x][i]);
return 0;
}

int main()
{
int i,j,k,cas,nod,edg,x,y;
cin>>cas;
while(cas--)
    {
    cin>>nod>>edg;
    for(i=0;i<nod;i++)
        cin>>a[i];
    for(i=0;i<edg;i++)
        {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        }
    int fl=0;
    for(i=0;i<nod;i++)
        if(color[i]==0)
            {
            sum=0;
            dfs(i);
            if(sum)
                {
                fl=1;
                break;
                }
            }
    if(!fl)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    for(i=0;i<=nod;i++)
        {
        v[i].clear();
        color[i]=0;
        }
    }
return 0;
}
