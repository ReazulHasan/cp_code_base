#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

char a[100][100];
int ro,co,sro,sco,ero,eco;
int color[100][100],cost[100][100];
int m[]={-1,0,0,1};
int n[]={0,-1,1,0};

int BFS()
{
int i,j,k;
queue<int> qro,qco;
color[sro][sco]=1;
cost[sro][sco]=0;
qro.push(sro);
qco.push(sco);
while(!qro.empty())
    {
    int r=qro.front();
    qro.pop();
    int c=qco.front();
    qco.pop();
    /*if(r==ero&&c==eco)
        return 0;*/
    for(i=0;i<4;i++)
        {
        int x=r+m[i];
        int y=c+n[i];
        if(x>=0&&x<ro&&y>=0&&y<co)
            if(a[x][y]!='#'&&color[x][y]==0)
                {
                color[x][y]=1;
                cost[x][y]=cost[r][c]+1;
                cout<<x<<" "<<y<<": "<<cost[x][y]<<endl;;
                qro.push(x);
                qco.push(y);
                }
        }
    }
}

int main()
{
int i,j,k;
while(cin>>ro>>co)
    {
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            {
            char c;
            cin>>c;
            a[i][j]=c;
            if(c=='S')
                {
                sro=i;
                sco=j;
                }
            if(c=='E')
                {
                ero=i;
                eco=j;
                }
            }
        BFS();
        cout<<cost[ero][eco]<<endl;
    //cout<<sro<<" "<<sco<<" : "<<ero<<eco<<endl;
    }
}
