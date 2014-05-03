#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

string s[500];
int ro[]={-1,-1,0,0,1,1};
int co[]={-1,0,-1,1,0,1};
int n,win=0,color[500][500];

int flood(int fl,int x,int y)
{
int i,j,k;
color[x][y]=1;
if(fl==1&&x==n-1)
    {
    win=1;
    return 0;
    }
if(fl==2&&y==n-1)
    {
    win=2;
    return 0;
    }
for(i=0;i<6;i++)
    {
    int a=x+ro[i];
    int b=y+co[i];
    if(a>=0&&a<n&&b>=0&&b<n)
        {
        if(fl==1)
            {
            if(s[a][b]=='b'&&color[a][b]==0)
                flood(1,a,b);
            }
        else if(fl==2)
            {
            if(s[a][b]=='w'&&color[a][b]==0)
                flood(2,a,b);
            }
        }
    }
return 0;
}

int main()
{
int i,j,k=0;
while(cin>>n&&n)
    {
    k++;
    for(i=0;i<n;i++)
        cin>>s[i];
    win=0;
    for(i=0;i<n;i++)
        {
        if(s[0][i]=='b')
            flood(1,0,i);
        if(s[i][0]=='w')
            flood(2,i,0);
        if(win)
            break;
        }
    cout<<k<<" ";
    if(win==1)
        cout<<"B"<<endl;
    else if(win==2)
        cout<<"W"<<endl;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            color[i][j]=0;
    }
return 0;
}
