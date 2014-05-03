//Bismillahir Rahmanir Rahim
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int edge[100][100],graph[100][100],p[109],q[109];

int input(int x)
{
int i,coun=1,index=0,j;
while(1)
    {
    coun++;
    edge[index][0]=x;
    for(i=1;i<=x;i++)
        cin>>edge[index][i];
    index++;
    if(coun==19)
        break;
    else
        cin>>x;
    }
    for(i=0;i<=19;i++)
        {
        for(j=1;edge[i][j]!=0;j++)
            {
            graph[i+1][edge[i][j]]=1;
            graph[edge[i][j]][i+1]=1;
            }
        }
return 0;
}
int bfs(int s,int d)
{
queue<int> q;
int color[50],cost[50],i,j;
for(i=0;i<50;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
color[s]=1;
q.push(s);
while(!q.empty())
    {
    int item=q.front();
    for(i=0;i<50;i++)
        {
        if(graph[item][i]==1)
            if(color[i]==0)
                {
                color[i]=1;
                cost[i]=cost[item]+1;
                q.push(i);
                }
        }
    color[item]=2;
    q.pop();
    }
return cost[d];
}

int main()
{
int i,j,n,s,d,t,coun=0;
while(cin>>t)
    {
    coun++;
    input(t);
    i=0;
    cin>>n;
    while(n)
        {
        n--;
        cin>>p[i]>>q[i];
        i++;
        }
        cout<<"Test Set #"<<coun<<endl;
        for(j=0;j<i;j++)
            {
            s=p[j]; d=q[j];
            int res=bfs(s,d);
            if(s<10)
                cout<<" "<<s;
            else
                cout<<s;
            cout<<" to ";
            if(d<10)
                cout<<" "<<d;
            else
                cout<<d;
            cout<<": "<<res<<endl;
            }
    cout<<endl;
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            {
            edge[i][j]=0;
            graph[i][j]=0;
            p[i]=0;
            q[i]=0;
            }
    }
return 0;
}

