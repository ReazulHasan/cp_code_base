        //Bismillahir Rahmanir Rahim

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int wh=1,gr=2,bl=3;
vector<int> v[100];
int color[100],dis[100],fin[100],prev[100];
int t=1;

int DFS(int a)
{
color[a]=gr;
dis[a]=t++;
int i,j,it;
int x=v[a].size();
for(i=0;i<x;i++)
    {
    it=v[a][i];
    //cout<<it<<endl;
    //v[a].pop_front();
    if(color[it]==wh)
        {
        prev[it]=a;
        DFS(it);
        }
    fin[it]=t++;
    color[it]=bl;
    }
return 0;
}

int main()
{
int a,b,n,i,j,s,d;
for(i=0;i<100;i++)
    {
    color[i]=wh;
    dis[i]=0;
    fin[i]=0;
    prev[i]=0;
    }
cin>>n;
for(i=1;i<=n;i++)
    {
    cin>>a>>b;
    v[a].push_back(b);
    }
cin>>s>>d;
color[s]=gr;
dis[s]=t++;
int x=v[s].size();
//cout<<x<<endl;
for(i=0;i<x;i++)
    {
    int it=v[s][i];
    if(color[it]==wh)
        DFS(it);
    fin[it]=t++;
    color[it]=bl;
    prev[it]=s;
    }
cout<<fin[d]<<endl;
return 0;
}
