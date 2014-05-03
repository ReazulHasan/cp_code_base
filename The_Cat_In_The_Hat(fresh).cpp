#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;

int flag[1000009];
ll prim[1000009];

struct ss{
    ll bas,p;
    };

int seive()
{
int i,j,k;
for(i=2;i*i<=1000000;i++)
    for(j=i+i;j<=1000000;j+=i)
        flag[j]=1;
prim[0]=2;
k=1;
for(i=3;i<=1000000;i+=2)
    if(flag[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";
cout<<endl;*/
return 0;
}

ll gcd(ll a,ll b)
{
if(b==0) return a;
return gcd(b,a%b);
}

int main()
{
int i,j,k;
ss t;
ll num,hit;
seive();
while(cin>>hit>>num)
    {
    vector<ss> v;
    if(!num&&!hit)
        break;
    ll n=num,last=-1,noty=0,mary=1,x=0,div;
    for(i=0;prim[i]*prim[i]<=n;i++)
        if(n%prim[i]==0)
            {
            //mary*=prim[i];
            int hm=0;
            while(n%prim[i]==0)
                {
                n/=prim[i];
                hm++;
                }
            t.bas=prim[i]; t.p=hm;
            v.push_back(t);
            ll gc=gcd(x,hm);
            x=gc;
            if(x==1)
                {
                noty=1;
                //break;
                }
            /*if(last==-1)
                last=hm;
            if(last!=hm)
                {
                noty=1;
                //break;
                }*/
            //cout<<prim[i]<<": "<<hm<<endl;
            }
    ll res=hit;
    //cout<<mary<<endl;
    if(hit==1&&num==1) {cout<<"0 1"<<endl;continue;}
    if(num==1&&hit>1)
        {
        int cun=0;
        while(hit>1)
            {
            cun++;
            res+=hit/2;
            hit/=2;
            }
        cout<<cun<<" "<<res<<endl;
        continue;
        }
    if(n==num)
        {
        res+=n*hit/(n+1);
        /*if(n==1)
            cout<<"0 "<<res<<endl;
        else*/
            cout<<"1 "<<res<<endl;
        continue;
        //v.push_back(n);
        }
    else if(n>1&&!noty)
        {
        noty=1;
        x=1;
        //cout<<"last: "<<n;
        /*if(last==1)
            {
            mary*=n;
            v.push_back(n);
            }
        else
            {
            //cout<<"hi"<<endl;
            noty=1;
            }*/
        }
    if(noty)
        {
        res+=num*hit/(num+1);
        cout<<"1 "<<res<<endl;
        }
    else
        {
        vector<ll> fact;
        map<ll,int> mp;
        mary=1;
        int ln=v.size(),gc=x;
        fact.push_back(1);
        for(i=0;prim[i]*prim[i]<=gc;i++)
            if(gc%prim[i]==0)
                {
                ll pr=1;
                while(gc%prim[i]==0)
                    {
                    pr*=prim[i];
                    gc/=prim[i];
                    //if(mp[pr]==0) fact.push_back(pr),mp[pr]=1;
                    int sz=fact.size();
                    for(j=0;j<sz;j++)
                        {
                        if(fact[j]%prim[i]==0)
                            continue;
                        ll hay=fact[j]*pr;
                        if(mp[hay]==0) fact.push_back(hay),mp[hay]=1;
                        }
                    }
                }
        if(gc>1)
            {
            int sz=fact.size();
            for(j=0;j<sz;j++)
                {
                if(fact[j]%gc==0)
                    continue;
                ll hay=fact[j]*gc;
                if(mp[hay]==0) fact.push_back(hay),mp[hay]=1;
                }
            }
        //cout<<"x: "<<x<<endl;
        int siz=fact.size();
        k=siz-1;
        /*for(i=0;i<siz;i++)
            cout<<fact[i]<<" ";
        cout<<endl;*/
        while(1)
            {
            if(k<0)
                break;
            mary=1;
            ll mal=fact[k];
            k--;
            ll hi=hit,lo;
            for(i=0;i<ln;i++)
                {
                //mary=1;
                t=v[i];
                ll po,ba;
                po=t.p;
                ba=t.bas;
                po/=x;
                po*=mal;
                //cout<<"base: "<<ba<<", pow: "<<po<<endl;
                for(j=0;j<po;j++)
                    mary*=ba;
                }
            lo=(mary+1);
            //cout<<ceil(hi/lo)<<" "<<floor(hi/lo)<<endl;
            while(hi%lo==0)
                {
                hi/=lo;
                if(hi==1)
                    break;
                }
            if(hi==1)
                break;
            //cout<<"mary: "<<mary<<endl;
            }
        //mary=784;
        //cout<<mary<<endl;
        n=num; res=hit;
        int inter=0,depth=0;
        while(n>1) inter+=n/mary,n/=mary,depth++;
        int mult=1,h=hit;
        for(i=0;i<depth;i++)
            {
            mult*=mary;
            h/=(mary+1);
            //cout<<mult*h<<" mult*h"<<endl;
            res+=mult*h;
            }
        cout<<inter<<" "<<res<<endl;
        }
    }
return 0;
}
