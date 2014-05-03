//Bismillahir rahmanir rahim
//This is my first code of "articulation point"

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> v[1000];
int art=0,color[1000],prev[1000],lo[1000],inf=9876543,dis[1000],tim=1,child[1000],star=0;
map<int,int> mp;

int DFS(int x)
{
int i,j;
dis[x]=tim;
color[x]=1;
lo[x]=tim;
tim++;
int len=v[x].size();
for(i=0;i<len;i++)
    {
    int y=v[x][i];
    if(color[y]==0)
        {
        child[x]++;
        prev[y]=x;
        DFS(y);
        if(lo[y]>=dis[x]&&prev[y]!=-1&&mp[x]==0&&x!=star)
            {
            mp[x]=1;
            //cout<<"x y dis[x] lo[y]: "<<x<<" "<<y<<" "<<dis[x]<<" "<<lo[y]<<endl;
            art++;
            }
        lo[x]=min(lo[x],lo[y]);
        }
    else
        lo[x]=min(lo[x],dis[y]);
    //cout<<x<<" : "<<lo[x]<<" ";
    }
//cout<<endl;
return 0;
}

int main()
{
char ch;
int i,j,k,n,now,m;
while(cin>>n&&n)
    {
    while(1)
        {
        cin>>now;
        if(!now)
            break;
        //if(now>0)
        while((ch=getchar())!='\n')
            {
            cin>>m;
            v[now].push_back(m);
            v[m].push_back(now);
            }
        }
    /*if(i==n)
        cin>>now;*/
    for(i=1;i<=n;i++)
        if(color[i]==0)
            {
            //coun=0;
            prev[i]=-1;
            star=i;
            DFS(i);
            if(child[i]>1)
                art++;
            }
    cout<<art<<endl;
    /*cout<<child[1]<<endl;
    for(j=0;j<=n;j++)
        {
        cout<<j<<": ";
        int len=v[j].size();
        for(k=0;k<len;k++)
            cout<<v[j][k]<<" ";
        cout<<endl;
        }*/
    for(i=0;i<=n;i++)
        {
        v[i].clear();
        color[i]=0;
        prev[i]=0;
        lo[i]=0;
        dis[i]=0;
        child[i]=0;
        }
    art=0; tim=1; star=0; mp.clear();
    }
return 0;
}
