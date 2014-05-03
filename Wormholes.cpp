    //Bismillah
    //My first BELLMAN FORD code

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;

#define inf 987654321

struct ss{
    int u,v;
};

ss edg[2000];
int cost[2000][2000];
int star,hol;
int res[5000];

void ini()
{
int i,j;
for(i=0;i<2000;i++)
    {
    for(j=0;j<2000;j++)
            cost[i][j]=0;
    edg[i].u=0;
    edg[i].v=0;
    res[i]=inf;
    }
res[0]=0;
}

int relax(int x,int y)
{
if(res[y]>(res[x]+cost[x][y]))
    res[y]=res[x]+cost[x][y];
return 0;
}

int bellman()
{
int i,j,k,x,y;
for(i=0;i<star;i++)
    for(j=0;j<hol;j++)
        {
        x=edg[j].u;
        y=edg[j].v;
        relax(x,y);
        }
int flag=0;
for(i=0;i<hol;i++)
    {
    int x=edg[i].u;
    int y=edg[i].v;
    if(res[y]>res[x]+cost[x][y])
        {
        cout<<"possible"<<endl;
        flag=1;
        break;
        }
    }
if(flag==0)
    cout<<"not possible"<<endl;
return 0;
}

int main()
{
ss t,d;
int cas,i,j,k,l;
cin>>cas;
while(cas--)
    {
    ini();
    int x,y,cos;
    cin>>star>>hol;
    for(i=0;i<hol;i++)
        {
        cin>>x>>y>>cos;
        t.u=x;
        t.v=y;
        edg[i]=t;
        cost[x][y]=cos;
        }
    /*for(i=0;i<hol;i++)
        cout<<edg[i].u<<edg[i].v<<" ";
    cout<<endl;
    for(i=0;i<star;i++)
        {
        for(j=0;j<star;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
        }*/
    bellman();
    }
return 0;
}
