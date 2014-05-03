//Allah, plz help me.
//Bismillahir Rahmanir Rahim
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

queue<int> myq;
set<int> myset;
int node[100][100],color[100],prev[100],cost[100],end;
int main()
{
int start,n,a,b,i,j,k;
cin>>n;
for(i=0;i<n;i++)
    {
    cin>>a>>b;
    node[a][b]=1;
    if(i==0)
        {
        start=a;
        }
    if(i==n-1)
        end=b;
    }
for(i=0;i<100;i++)
    {
    color[i]=0;
    prev[i]=-1;
    cost[i]=0;
    }
color[start]=1;
int item;
myq.push(start);
while(!myq.empty())
    {
    item=myq.front();
    for(j=0;j<100;j++)
        {
        if(node[item][j]==1)
            {
            if(color[j]==0)
                {
                color[j]=1;
                cost[j]=cost[item]+1;
                prev[j]=item;
                myq.push(j);
                cout<<"cost of "<<j<<" is "<<cost[j]<<endl;
                }
            }
        }
        color[item]=2;
        myq.pop();
    }
cout<<"minimum cost to reach destination is: "<<cost[end]<<endl;
cout<<"The shortest path to reach destination is: ";
i=prev[end];
while(i>=start)
    {
        cout<<i<<" ";
        i=prev[i];
    }
return 0;
}
