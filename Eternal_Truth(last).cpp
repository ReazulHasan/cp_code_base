#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

char a[500][500],dekh[500][500][5];
int ro,co,sro,sco,ero,eco;
int bar[5][5],bac[5][5],mos[500][500][5];

int BFS(int p,int q)
{
int i,j,k;
queue<int> qro,qco,qinc;
qro.push(p);
qco.push(q);
qinc.push(1);
mos[p][q][1]=0;
int r,c,inc=1,coun=0,nr,nc,x,y;
while(!qro.empty())
    {
    r=qro.front();
    qro.pop();
    c=qco.front();
    qco.pop();
    inc=qinc.front();
    qinc.pop();
    if(r==ero&&c==eco)
        return mos[ero][eco][inc];
    //cout<<"r c inc cost"<<r<<" "<<c<<" "<<inc<<" "<<mos[r][c][inc]<<endl;
    for(i=0;i<4;i++)
        {
        int flg=0;
        x=bar[inc][i]; y=bac[inc][i];
        nr=r+x;
        nc=c+y;
        //cout<<nr<<" "<<nc<<endl;
       if(nr>=0&&nr<ro&&nc>=0&&nc<co)
            {
            if(x==0)
                {
                if(y<0)
                    {
                    for(j=-1;j>=y;j--)
                        if(a[r][c+j]=='#')
                            flg=1;
                    }
                else
                    {
                    for(j=1;j<=y;j++)
                        if(a[r][c+j]=='#')
                            flg=1;
                    }
                }
            else if(y==0)
                {
                if(x<0)
                    {
                    for(j=-1;j>=x;j--)
                        if(a[r+j][c]=='#')
                            flg=1;
                    }
                else
                    {
                    for(j=1;j<=x;j++)
                        if(a[r+j][c]=='#')
                            flg=1;
                    }
                }
            if(flg==0)
                {
                int mu;
                if(inc==3)
                    mu=1;
                    //qinc.push(1);
                else if(inc<3)
                    mu=inc+1;
                    //qinc.push(inc+1);

                if(dekh[nr][nc][mu]==0)
                    {
                    dekh[nr][nc][mu]=1;
                    mos[nr][nc][mu]=mos[r][c][inc]+1;
                    //cout<<"  nr nc inc cost"<<nr<<" "<<nc<<" "<<mu<<" "<<mos[nr][nc][mu]<<endl;
                    qro.push(nr);
                    qco.push(nc);
                    qinc.push(mu);
                    //dekh[nr][nc]+=1;
                    }
                }
            }
        }
    }
return -1;
}

int main()
{
int i,j,k,cas;
bar[1][0]=-1; bar[1][1]=0; bar[1][2]=0; bar[1][3]=1;
bac[1][0]=0; bac[1][1]=-1; bac[1][2]=1; bac[1][3]=0;
for(i=2;i<=3;i++)
    for(j=0;j<4;j++)
        {
        if(i==2)
            {
            bar[i][j]=bar[i-1][j]*2;
            bac[i][j]=bac[i-1][j]*2;
            }
        if(i==3)
            {
            bar[i][j]=bar[i-2][j]*3;
            bac[i][j]=bac[i-2][j]*3;
            }
        }
cin>>cas;
while(cas--)
    {
    cin>>ro>>co;
    for(i=0;i<=ro;i++)
        for(j=0;j<=co;j++)
            {
            for(k=0;k<4;k++)
                {
                dekh[i][j][k]=0;
                mos[i][j][k]=0;
                }
            }
    for(i=0;i<ro;i++)
        cin>>a[i];
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            {
            if(a[i][j]=='S')
                {
                sro=i; sco=j;
                }
            if(a[i][j]=='E')
                {
                ero=i; eco=j;
                }
            }
    dekh[sro][sco][1]=1;
    int res=BFS(sro,sco);
    if(res==-1)
        cout<<"NO"<<endl;
    else
        cout<<res<<endl;
    }
return 0;
}
