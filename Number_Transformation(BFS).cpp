#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define sz 1500

int a[sz+3],prim[sz+3];
vector<int> v[sz+3];

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=0;
for(i=2;i<=sz;i++)
    {
    if(a[i]==0)
        prim[k++]=i;
    else
        {
        int it=i;
        for(j=0;prim[j]*prim[j]<=it;j++)
            {
            int fl=0;
            while(it%prim[j]==0)
                {
                fl=1;
                it/=prim[j];
                }
            if(fl)
                v[i].push_back(prim[j]);
            }
        if(it>1&&it<i)
            v[i].push_back(it);
        }
    }
/*for(i=0;i<100;i++)
    {
    int len=v[i].size();
    cout<<i<<" : ";
    for(j=0;j<len;j++)
        cout<<v[i][j]<<" ";
    cout<<endl;
    }*/
return 0;
}

int flg=0;

int BFS(int num,int tar)
{
int i,j,k;
int color[sz+3],cost[sz+3];
for(i=0;i<sz;i++)
    {
    color[i]=0;
    cost[i]=0;
    }
queue<int> q;
q.push(num);
color[num]=1;
cost[num]=0;
while(!q.empty())
    {
    int it=q.front();
    q.pop();
    if(it==tar)
        {
        cout<<cost[it]<<endl;
        flg=1;
        break;
        }
    int len=v[it].size();
    for(i=(len-1);i>=0;i--)
        {
        int x=it+v[it][i];
        //cout<<x<<" ";
        if(color[x]==0&&x<=tar)
            {
            color[x]=1;
            cost[x]=cost[it]+1;
            q.push(x);
            }
        }
    }
return 0;
}

int main()
{
seive();
int i,j,k,num,tar,coun=0;
while(cin>>num>>tar)
    {
    coun++;
    if(num==0&&tar==0)
        break;
    cout<<"Case "<<coun<<": ";
    flg=0;
    BFS(num,tar);
    if(flg==0)
        cout<<"-1"<<endl;
    }
return 0;
}
