#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define maxn 50000
int wh=0,gr=1,bl=2,coun=0;

int color[maxn];
vector<int> v[40000];

int dfs(int n)
{
int i,j;
color[n]=gr;
int x=v[n].size();
for(i=0;i<x;i++)
    {
    int it=v[n][i];
    if(color[it]==wh)
        {
        coun++;
        dfs(it);
        }
    }
return 0;
}

int main()
{
int t,i,j,a,b,m,n;
cin>>t;
while(t--)
    {
    for(i=0;i<40000;i++)
        v[i].clear();
    for(i=0;i<maxn;i++)
        color[i]=wh;
    cin>>m>>n;
    int k=n;
    while(k--)
        {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        }
    int hi=0;
    for(i=1;i<=m;i++)
        {
        coun=0;
        if(color[i]==wh)
            {
            coun++;
            int x=dfs(i);
            }
        if(hi<coun)
            hi=coun;
        }
    cout<<hi<<endl;
    }
return 0;
}
