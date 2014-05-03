#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

string s[100];
int flag[100][100],n,coun=0;
int ro[]={-1,1,0,0,-1,-1,1,1};
int co[]={0,0,-1,1,-1,1,-1,1};

int flood(int a,int b)
{
int i,j,k,x,y;
coun++;
flag[a][b]=1;
for(i=0;i<8;i++)
    {
    x=a+ro[i]; y=b+co[i];
    if(x>=0&&y>=0&&x<n&&y<n)
        if(s[x][y]=='1'&&flag[x][y]==0)
            flood(x,y);
    }
return 0;
}

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
while(cas--)
    {
    cin>>s[0];
    int len=s[0].size();
    n=len;
    for(i=1;i<len;i++)
        cin>>s[i];
    if(kas) cout<<endl;
    kas=1;
    int maxn=0;
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
            if(flag[i][j]==0&&s[i][j]=='1')
                {
                coun=0;
                flood(i,j);
                if(maxn<coun)
                    maxn=coun;
                }
    cout<<maxn<<endl;
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
            flag[i][j]=0;
    }
return 0;
}
