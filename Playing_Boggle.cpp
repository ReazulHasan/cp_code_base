#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
using namespace std;
int p[]={-1,-1,-1,0,0,1,1,1};
int r[]={-1,0,1,-1,1,-1,0,1};
char board[10][10],inp[200][200];
queue<char> q;
map<int,int> mp;

int flood(int ro,int co)
{
int i,j,k;
char it;
mp[(4*ro+co)]=1;
if(!q.empty())
    it=q.front();
else return 0;
for(i=0;i<8;i++)
    {
    int x=ro+p[i];
    int y=co+r[i];
    if(x>=0&&x<4&&y>=0&&y<4)
        if(board[x][y]==it&&mp[4*x+y]==0)
            {
            q.pop();
            flood(x,y);
            }
    }
return 0;
}

int main()
{
int t,n,i,j,k;
cin>>t;
while(t--)
    {
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin>>board[i][j];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>inp[i];
    for(i=0;i<n;i++)
        {
        //q.clear();
        mp.clear();
        int len=strlen(inp[i]);
        for(j=0;j<len;j++)
            q.push(inp[i][j]);
        char it=q.front();
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                if(board[j][k]==it)
                    {
                    q.pop();
                    flood(j,k);
                    }
        if(!q.empty())
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
        while(!q.empty())
            q.pop();
        }
    }
return 0;
}
