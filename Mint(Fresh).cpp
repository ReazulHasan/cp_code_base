#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int coin[1000],prim[1000009],flag[1000009],koybar[10000009];
int seive()
{
int i,j,k;
for(i=2;i*i<1000000;)
    {
    for(j=i+i;j<1000000;j+=i)
        flag[j]=1;
    for(i++;flag[i];i++);
    }
k=1;
prim[0]=2;
for(i=3;i<1000000;i+=2)
    if(flag[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

vector<int> v,now,fin;

int LCM()
{
int i,j,k;
map<int,int> mp;
for(j=0;j<4;j++)
{
int a=now[j];
for(i=0;prim[i]*prim[i]<=a;i++)
    {
    if(a%prim[i]==0)
        {
        int coun=0;
        while(a%prim[i]==0)
            {
            coun++;
            a/=prim[i];
            }
        if(koybar[prim[i]]<coun)
            koybar[prim[i]]=coun;
        if(mp[prim[i]]==0)
            {
            mp[prim[i]]=1;
            v.push_back(prim[i]);
            }
        }
    }
    if(a>1)
        {
        if(koybar[a]<1)
            koybar[a]=1;
        if(mp[a]==0)
            {
            mp[a]=1;
            v.push_back(a);
            }
        }
}
int len=v.size();
long long lc=1;
for(i=0;i<len;i++)
    {
    int pr=v[i];
    int bar=koybar[pr];
    for(j=1;j<=bar;j++)
        lc*=pr;
    koybar[pr]=0;
    }
fin.push_back(lc);
v.clear();
return 0;
}

int main()
{
seive();
int i,j,k,m,con,table;
while(cin>>con>>table)
    {
    if(con==0&&table==0)
        break;
    for(i=0;i<con;i++)
        cin>>coin[i];
    for(i=0;i<con;i++)
        for(j=i+1;j<con;j++)
            for(k=j+1;k<con;k++)
                for(m=k+1;m<con;m++)
                    {
                    now.push_back(coin[i]);
                    now.push_back(coin[j]);
                    now.push_back(coin[k]);
                    now.push_back(coin[m]);
                    LCM();
                    now.clear();
                    }
    int leg;
    /*int ln=fin.size();
    for(i=0;i<ln;i++)
        cout<<fin[i]<<" ";
    cout<<endl;*/
    for(m=0;m<table;m++)
        {
        cin>>leg;
        long long minm=0,maxm=98765498;
        int len=fin.size(),fl=0;
        for(i=0;i<len;i++)
            {
            int x=fin[i];
            if(x<=leg)
                {
                fl=1;
                int y=x;
                while((y+x)<=leg)
                    y+=x;
                if(y==leg)
                    {
                    maxm=leg;
                    minm=leg;
                    break;
                    }
                if(y>minm)
                    minm=y;
                if((y+x)<maxm)
                    maxm=y+x;
                }
            else if(x<maxm)
                maxm=x;
            }
        cout<<minm<<" "<<maxm<<endl;
        }
    fin.clear();
    }
return 0;
}
