#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

char a[100][100];
int color[100][100];
int p[]={-1,-1,-1,0,0,1,1,1};
int q[]={-1,0,1,-1,1,-1,0,1};
int n;

int flood(int ro,int co)
{
int i,j,k;
color[ro][co]=1;
for(i=0;i<8;i++)
    {
    int x=ro+p[i];
    int y=co+q[i];
    if(x>=0&&x<n&&y>=0&&y<n)
        if(a[x][y]=='1'&&color[x][y]==0)
            flood(x,y);
    }
return 0;
}

int main()
{
int i,j,k,cas=0;
while(cin>>n)
    {
    cas++;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    int coun=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]=='1'&&color[i][j]==0)
                {
                coun++;
                flood(i,j);
                }
    cout<<"Image number "<<cas<<" contains "<<coun<<" war eagles."<<endl;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            color[i][j]=0;
    }
return 0;
}
