#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
using namespace std;

char a[50][50][50];
int lev,ro,co,slev,sro,sco,elev,ero,eco;
int color[50][50][50],cost[50][50][50];
int m[]={-1,0,0,1};
int n[]={0,-1,1,0};

int BFS()
{
int i,j,k;
queue<int> qlev,qro,qco;
color[slev][sro][sco]=1;
cost[slev][sro][sco]=0;
qlev.push(slev);
qro.push(sro);
qco.push(sco);
while(!qro.empty())
    {
    //cout<<"hi"<<endl;
    int l=qlev.front();
    qlev.pop();
    int r=qro.front();
    qro.pop();
    int c=qco.front();
    qco.pop();
    if(r==ero&&c==eco&&l==elev)
        return 1;
    //cout<<"hui"<<endl;
    if(l>0)
        if(a[l-1][r][c]!='#'&&color[l-1][r][c]==0)
            {
            color[l-1][r][c]=1;
            cost[l-1][r][c]=cost[l][r][c]+1;
            qlev.push(l-1);
            qro.push(r);
            qco.push(c);
            }
    if(l<(lev-1))
        if(a[l+1][r][c]!='#'&&color[l+1][r][c]==0)
            {
            color[l+1][r][c]=1;
            cost[l+1][r][c]=cost[l][r][c]+1;
            qlev.push(l+1);
            qro.push(r);
            qco.push(c);
            }
    for(i=0;i<4;i++)
        {
        int x=r+m[i];
        int y=c+n[i];
        if(x>=0&&x<ro&&y>=0&&y<co)
                if(a[l][x][y]!='#'&&color[l][x][y]==0)
                    {
                    color[l][x][y]=1;
                    cost[l][x][y]=cost[l][r][c]+1;
                    qlev.push(l);
                    qro.push(x);
                    qco.push(y);
                    if(l>0)
                        if(a[l-1][x][y]!='#'&&color[l-1][x][y]==0)
                            {
                            color[l-1][x][y]=1;
                            cost[l-1][x][y]=cost[l][x][y]+1;
                            qlev.push(l-1);
                            qro.push(x);
                            qco.push(y);
                            }
                    if(l<(lev-1))
                        if(a[l+1][x][y]!='#'&&color[l+1][x][y]==0)
                            {
                            color[l+1][x][y]=1;
                            cost[l+1][x][y]=cost[l][x][y]+1;
                            qlev.push(l+1);
                            qro.push(x);
                            qco.push(y);
                            }
                    }
        }
    }
return 0;
}


int main()
{
int i,j,k;
while(cin>>lev>>ro>>co)
    {
    if(lev==0&&ro==0&&co==0)
        break;
    if(lev==1&&ro==1&&co==1)
        {
        char ch;
        cin>>ch;
        if(ch=='S')
            cout<<"Trapped!"<<endl;
        else if(ch=='E')
            cout<<"Escaped in "<<"0"<<" minute(s)."<<endl;
        else
            cout<<"Trapped!"<<endl;
        }
    else
        {
    for(i=0;i<lev;i++)
        for(j=0;j<ro;j++)
            for(k=0;k<co;k++)
                {
                a[i][j][k]='\0';
                color[i][j][k]=0;
                cost[i][j][k]=0;
                }
    for(i=0;i<lev;i++)
        for(j=0;j<ro;j++)
            for(k=0;k<co;k++)
                {
                char c;
                cin>>c;
                a[i][j][k]=c;
                if(c=='S')
                    {
                    slev=i;
                    sro=j;
                    sco=k;
                    //cout<<i<<j<<k<<endl;
                    }
                if(c=='E')
                    {
                    elev=i;
                    ero=j;
                    eco=k;
                    //cout<<i<<j<<k<<endl;
                    }
                }
        int resho=BFS();
        if(cost[elev][ero][eco]==0)
            cout<<"Trapped!"<<endl;
        else
            cout<<"Escaped in "<<cost[elev][ero][eco]<<" minute(s)."<<endl;
        }
    }
return 0;
}
