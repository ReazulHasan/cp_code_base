#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

char a[1000][1000];
int i,j;
int as[]={0,-1,-1,-1,0,1,1,1};
int bs[]={-1,-1,0,1,1,-1,0,1};

int BFS()
{
int color[100][100],cost[1000],s,t;
deque<int>dq1,dq2;
for(s=0;s<100;s++)
    for(t=0;t<100;t++)
        color[s][t]=0;
color[i][j]=0;
dq1.push_back(i);
dq2.push_back(j);
while(!dq1.empty())
    {
    int nw1=dq1.front();
    dq1.pop_front();
    int nw2=dq2.front();
    dq2.pop_front();
    for(s=0;s<8;s++)
        {
        int x=nw1+as[s];
        int y=nw2+bs[s];
        if(a[x][y]=='@'&&color[x][y]==0&&x>=0&&y>=0)
            {
            a[x][y]='0';
            color[x][y]=1;
            dq1.push_back(x);
            dq2.push_back(y);
            }
        }
    }
return 0;
}

int main()
{
int k,r,c;
while(cin>>r>>c)
    {
    if(r==0||c==0)
        break;
    int coun=0;
    for(i=0;i<r;i++)
        cin>>a[i];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            {
            if(a[i][j]=='@')
                {
                a[i][j]='0';
                BFS();
                coun++;
                }
            }
    cout<<coun<<endl;
    }
return 0;
}
