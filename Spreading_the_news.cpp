#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define sz 3000

vector<int> v[sz+3];
int color[sz+3],cost[sz+3],b[sz+3];

int BFS(int s)
{
int i;
for(i=0;i<sz;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
queue<int> q;
color[s]=1;
cost[s]=0;
q.push(s);
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    int len=v[it].size();
    for(i=0;i<len;i++)
        {
        if((color[v[it][i]])==0)
            {
            color[v[it][i]]=1;
            cost[v[it][i]]=cost[it]+1;
            q.push(v[it][i]);
            }
        }
    }
return 0;
}

int main()
{
int t,i=0,j,r,x,cas,s;
cin>>t;
int b[t];
for(i=0;i<t;i++)
    {
    cin>>r;
    for(j=0;j<r;j++)
        {
        cin>>x;
        v[i].push_back(x);
        }
    }
cin>>cas;
while(cas--)
    {
    for(i=0;i<t;i++)
        b[i]=0;
    cin>>s;
    BFS(s);
    for(i=0;i<t;i++)
        {
        //cout<<cost[i]<<" ";
        if(cost[i]!=0)
            b[cost[i]]++;
        }
    int m=0,d;
    for(i=0;i<t;i++)
        if(m<b[i])
        {
        m=b[i];
        d=i;
        }
    if(m==0)
        cout<<"0";
    else
        cout<<m<<" "<<d;
    //if(cas>0)
        cout<<endl;
    }
return 0;
}
