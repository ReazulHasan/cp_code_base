#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

map<int,int> mp;

int precalc()
{
int i,j,k,now=1;
i=7;
while(i*now<=100000)
    {
    mp[i*now]=1;
    now++;
    }
for(i=8;i<=100000;i++)
    {
    int x=i,fl=0;
    while(x>0)
        {
        if(x%10==7)
            {
            fl=1;
            break;
            }
        x/=10;
        }
    if(fl)
        mp[i]=1;
    }
return 0;
}

int main()
{
int i,j,k,tot,man,clap;
precalc();
while(cin>>tot>>man>>clap)
    {
    int a[200];
    if(!tot&&!man&&!clap)
        break;
    for(i=0;i<=tot;i++)
        a[i]=0;
    int now=1,coun=0,ho=0,res=-1;
    while(1)
        {
        ho++;
        if(ho%2)
            {
            if(ho==1)
                now=1;
            else
                now=2;
            for(i=now;i<=tot;i++)
                {
                coun++;
                if(mp[coun]==1)
                    a[i]++;
                if(a[man]==clap)
                    {
                    res=coun;
                    break;
                    }
                }
            }
        else
            for(i=tot-1;i>0;i--)
                {
                coun++;
                if(mp[coun]==1)
                    a[i]++;
                if(a[man]==clap)
                    {
                    res=coun;
                    break;
                    }
                }
        if(res>0)
            {
            cout<<res<<endl;
            break;
            }
        }
    }
return 0;
}
