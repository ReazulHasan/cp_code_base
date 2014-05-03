#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

int flag[1000009];
ll prim[1000009];

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

int main()
{
int i,j,k;
ll num,hit;
seive();
while(cin>>hit>>num)
    {
    vector<int> v;
    if(!num&&!hit)
        break;
    ll n=num,last=-1,noty=0,mary=1;
    for(i=0;prim[i]*prim[i]<=n;i++)
        if(n%prim[i]==0)
            {
            mary*=prim[i];
            v.push_back(prim[i]);
            int hm=0;
            while(n%prim[i]==0)
                {
                n/=prim[i];
                hm++;
                }
            if(last==-1)
                last=hm;
            if(last!=hm)
                {
                noty=1;
                //break;
                }
            cout<<prim[i]<<": "<<hm<<endl;
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
        //cout<<"last: "<<n;
        if(last==1)
            {
            mary*=n;
            v.push_back(n);
            }
        else
            {
            //cout<<"hi"<<endl;
            noty=1;
            }
        }
    if(noty)
        {
        res+=n*hit/(n+1);
        cout<<"1 "<<res<<endl;
        }
    else
        {
        n=num; res=hit;
        int inter=0,depth=0;
        while(n>1) inter+=n/mary,n/=mary,depth++;
        //inter++;
        int mult=1,h=hit;
        for(i=0;i<depth;i++)
            {
            mult*=mary;
            h/=(mary+1);
            res+=mult*h;
            }
        cout<<inter<<" "<<res<<endl;
        }
    }
return 0;
}
