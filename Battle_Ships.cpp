#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;

char a[200][200];
int color[200][200],n;
int dir1[]={0,1,-1,0};
int dir2[]={1,0,0,-1};

int DFS(int x,int y)
{
int i,j,k;
color[x][y]=1;
for(i=0;i<4;i++)
    {
    int p=x+dir1[i];
    int q=y+dir2[i];
    if(p>=0&&q>=0&&p<n&&q<n)
        if((a[p][q]=='x'||a[p][q]=='@')&&color[p][q]==0)
            DFS(p,q);
    }
return 0;
}

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
while(cas--)
    {
    kas++;
    int coun=0;
    cin>>n;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            {
            a[i][j]='/0';
            color[i][j]=0;
            }
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]=='x'&&color[i][j]==0)
                {
                coun++;
                DFS(i,j);
                }
    cout<<"Case "<<kas<<": "<<coun<<endl;
    }
return 0;
}
