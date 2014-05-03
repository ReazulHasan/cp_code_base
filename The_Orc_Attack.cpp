#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;

int cost[500][500];
int inf=99876598;

int main()
{
int i,j,k,cas,node,edg,x,y,c,kas=0;
cin>>cas;
while(cas--)
    {
    kas++;
    vector<int> v;
    cin>>node>>edg;
    for(i=1;i<=node;i++)
        {
        for(j=1;j<=node;j++)
            {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=inf+j+i;
            }
        }
    for(i=1;i<=edg;i++)
        {
        cin>>x>>y>>c;
        if(c<cost[x][y])
            cost[x][y]=c;
        if(c<cost[y][x])
            cost[y][x]=c;
        }
    for(k=1;k<=node;k++)
        for(i=1;i<=node;i++)
            for(j=1;j<=node;j++)
                if(cost[i][j]>cost[i][k]+cost[k][j])
                    cost[i][j]=cost[i][k]+cost[k][j];
    for(i=6;i<=node;i++)
        {
        int flag=1;
        int m1=cost[i][1];
        for(j=1;j<=5;j++)
            {
            int m2=cost[i][j];
            if(m1!=m2)
                {
                flag=0;
                break;
                }
            }
        if(flag)
            v.push_back(i);
        }
    int mini=9875698;
    int len=v.size();
    if(len==0)
        cout<<"Map "<<kas<<": -1"<<endl;
    else
        {
        int fl=0;
        for(i=0;i<len;i++)
            {
            int maxn=0;
            int now=v[i];
            for(j=1;j<=node;j++)
                if(maxn<cost[now][j])
                    maxn=cost[now][j];
            if(maxn<mini)
                {
                fl=1;
                mini=maxn;
                }
            }
        if(fl)
            cout<<"Map "<<kas<<": "<<mini<<endl;
        else
            cout<<"Map "<<kas<<": -1"<<endl;
        }
    }
return 0;
}
