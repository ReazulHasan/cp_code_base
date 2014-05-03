#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;

char a[150][150];
int x,y,len;
int g[]={0,-1,-1,-1,0,1,1,1};
int h[]={-1,-1,0,1,1,-1,0,1};

int BFS()
{
int i,j,k,color[150][150],cost[150],coun=0;
deque<int>dq1,dq2;
for(i=0;i<150;i++)
    for(j=0;j<150;j++)
        color[i][j]=0;

dq1.push_back(x);
dq2.push_back(y);
color[x][y]=0;
while(!dq1.empty())
    {
    coun++;
    int nw1=dq1.front();
    dq1.pop_front();
    int nw2=dq2.front();
    dq2.pop_front();
    for(i=0;i<8;i++)
        if(a[nw1+g[i]][nw2+h[i]]=='W'&&color[nw1+g[i]][nw2+h[i]]==0)
            {
            color[nw1+g[i]][nw2+h[i]]=1;
            dq1.push_back(nw1+g[i]);
            dq2.push_back(nw2+h[i]);
            }
    }
return coun-1;
}

int main()
{
int t,m,n,i,j;
cin>>t;
for(m=0;m<t;m++)
    {
    cin>>n;
    for(j=0;j<n;j++)
        cin>>a[j];

    while(cin>>x>>y)
        {
        x--; y--;
        int res;
        res=BFS();
        cout<<res<<endl;
        }
    }
}
