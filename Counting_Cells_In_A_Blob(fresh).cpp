#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

string s[100];
int flag[100][100],r,c,coun=0;
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
    if(x>=0&&y>=0&&x<r&&y<c)
        if(s[x][y]=='1'&&flag[x][y]==0)
            flood(x,y);
    }
return 0;
}

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
//getline(cin,s[0]);
while(cas--)
    {
    k=0;
    cin>>s[0];
    /*while(cin>>s[k])
        {
        if(s[k].size()==0)
            break;
        k++;
        }*/
    int len=s[0].size();
    for(i=1;i<len;i++)
        cin>>s[i];
    r=len; c=len;
    //cout<<r<<" "<<c<<endl;
    if(kas) cout<<endl;
    kas=1;
    int maxn=0;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(flag[i][j]==0&&s[i][j]=='1')
                {
                coun=0;
                flood(i,j);
                if(maxn<coun)
                    maxn=coun;
                }
    cout<<maxn<<endl;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            flag[i][j]=0;
    }
return 0;
}
