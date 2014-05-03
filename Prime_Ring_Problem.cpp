#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int fl[1009],prim[1009],ar[1009],color[1009],res[25][50009][25];
map<int,int> mpri;
vector<int> v[100];

int seive()
{
int i,j,k;
for(i=2;i*i<100;)
    {
    for(j=i+i;j<100;j+=i)
        fl[j]=1;
    for(i++;fl[i];i++);
    }
k=1;
prim[0]=2;
mpri[2]=1;
for(i=3;i<100;i+=2)
    if(fl[i]==0)
        {
        prim[k++]=i;
        mpri[i]=1;
        }
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";
cout<<endl;*/
return 0;
}

int coun=0,pos=0;

int back_track(int star,int n)
{
int i,j,k;
if(star==n)
    {
    if(mpri[ar[n-1]+1])
        {
        pos++;
        for(i=0;i<n;i++)
            {
            res[n][pos][i]=ar[i];
            //cout<<ar[i]<<" ";
            }
        //cout<<endl;
        coun++;
        }
    }
else
    {
    //for(i=star;i<=n;i++)
    int now=ar[star-1];
    int len=v[now].size();
    for(j=0;j<len;j++)
        {
        if(v[now][j]<=n)
            {
            if(color[v[now][j]]==0)
                {
                color[v[now][j]]=1;
                ar[star]=v[now][j];
                back_track(star+1,n);
                color[v[now][j]]=0;
                }
            }
        else
            break;
        }
    }
return 0;
}

int main()
{
seive();
int i,j,k;
for(i=1;i<=16;i++)
    {
    for(j=1;j<=16;j++)
        if(i!=j&&mpri[i+j]==1)
            v[i].push_back(j);
    }
ar[0]=1;
color[1]=1;
for(i=1;i<=16;i++)
    {
    coun=0;
    for(j=2;j<=16;j++)
        color[j]=0;
    pos=0;
    back_track(1,i);
    res[i][0][0]=pos;
    //cout<<i<<" "<<coun<<endl;
    }
int x,cas=0;
while(cin>>x)
    {
    if(cas)
        cout<<endl;
    cas++;
    cout<<"Case "<<cas<<":"<<endl;
    int lim=res[x][0][0];
    for(i=1;i<=lim;i++)
        {
        cout<<"1";
        for(j=1;j<x;j++)
            cout<<" "<<res[x][i][j];
        cout<<endl;
        }
    }
//cout<<coun<<endl;
/*for(i=1;i<=16;i++)
    {
    cout<<i<<" : ";
    int ln=v[i].size();
    for(j=0;j<ln;j++)
        cout<<v[i][j]<<" ";
    cout<<endl;
    }*/
return 0;
}
