#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<map>
using namespace std;

int coin[1000009],prim[1000009],flg[1000009];

struct ss{
    int pr,tim;
};

int seive()
{
int i,j,k;
for(i=2;i<1000000;)
    {
    for(j=i+i;j<1000000;j+=i)
        flg[j]=1;
    for(i++;flg[i];i++);
    }
prim[0]=2;
k=1;
for(i=3;i<1000000;i+=2)
    if(flg[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int main()
{
seive();
ss t;
int i,j,k,con,lg;
while(cin>>con>>lg)
    {
    vector<ss> v;
    map<long long,int> mp;
    if(con==0&&lg==0)
        break;
    for(i=0;i<con;i++)
        cin>>coin[i];
    for(i=0;i<con;i++)
        {
        int x=coin[i];
        for(j=0;prim[j]*prim[j]<=x;j++)
            {
            int ko=0;
            if(x%prim[j]==0)
                {
                ko=1;
                int coun=0;
                while(x%prim[j]==0)
                    {
                    coun++;
                    x/=prim[j];
                    }
                if(mp[prim[j]]==0)
                    {
                    mp[prim[j]]=1;
                    t.pr=prim[j];
                    t.tim=coun;
                    v.push_back(t);
                    }
                else
                    {
                    int len=v.size();
                    for(k=0;k<len;k++)
                        {
                        if(v[k].pr==prim[j])
                            {
                            if(v[k].tim<coun)
                                {
                                v[k].tim=coun;
                                }
                            break;
                            }
                        }
                    }
                }
            }
        if(x>1)
            {
            int coun=1;
            if(mp[x]==0)
                {
                mp[x]=1;
                t.pr=x;
                t.tim=coun;
                v.push_back(t);
                }
            }
        }
    unsigned long long LC=1;
    int len=v.size();
    for(i=0;i<len;i++)
        {
        unsigned long long mult=1;
        int pri=v[i].pr;
        int bar=v[i].tim;
        for(j=0;j<bar;j++)
            LC*=pri;
        }
    cout<<LC<<endl;
    unsigned long long leg;
    for(i=0;i<lg;i++)
        {
        unsigned long long res=LC,fin=LC;
        cin>>leg;
        //cout<<"hi"<<endl;
        if(leg%LC==0)
            cout<<leg<<" "<<leg<<endl;
        else if(leg<LC)
            cout<<"0 "<<LC<<endl;
        else
            {
            int m=1;
            while(leg>fin)
                {
                m++;
                fin=res*m;
                }
            cout<<fin-LC<<" "<<fin<<endl;
            }
        }
    }
return 0;
}
