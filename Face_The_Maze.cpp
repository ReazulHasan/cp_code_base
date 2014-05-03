#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<deque>
#include<map>
using namespace std;

int stari,starj,desti,destj,n,color[500][500],flag[500][500];
int p[]={0,1,-1,0};
int q[]={1,0,0,-1}

int BFS(int x,int y)
{
queue<int> qi,qj;
qi.push(x);
qj.push(y);
color[x][y]=1;
while(!qi.empty())
    {
    int a=qi.front();
    qi.pop();
    int b=qj.front();
    qj.pop();
    for(i=0;i<4;i++)
    }
}

int main()
{
int cas,ro,co;
cin>>cas;
while(cas--)
    {
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>co>>ro;
        if(i==0)
            {
            stari=ro-1;
            starj=co-1;
            }
        if(i==1)
            {
            desti=ro-1;
            destj=co-1;
            }
        else
            flag[ro-1][co-1]=1;
        }
    BFS(stari,starj);
    }
return 0;
}
