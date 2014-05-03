#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
typedef long long ll;
using namespace std;

int flg[1000009];
ll prim[1000009];

int seive()
{
int i,j,k;
for(i=2;i*i<=1000000;i++)
    for(j=i+i;j<=1000000;j+=i)
        flg[j]=1;
prim[0]=2;
k=1;
for(i=3;i<=1000000;i+=2)
    if(flg[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int main()
{
int i,j,k;
ll num,bas;
seive();
while(cin>>num>>bas)
    {
    vector<ll> v;
    map<ll,int> mp;
    ll x=bas;
    for(i=0;prim[i]*prim[i]<=x;i++)
        {
        if(x%prim[i]==0)
            {
            int coun=0;
            while(x%prim[i]==0)
                {
                coun++;
                x/=prim[i];
                }
            v.push_back(prim[i]);
            mp[prim[i]]=coun;
            }
        }
    if(x>1)
        {
        v.push_back(x);
        mp[x]=1;
        }
    int len=v.size();
    ll mx=21474836478LL;
    for(i=0;i<len;i++)
        {
        ll x=v[i];
        ll y=num,tot=0;
        while(y>0)
            {
            tot+=y/x;
            y/=x;
            }
        tot/=mp[x];
        if(mx>tot)
            mx=tot;
        }
    double dig=0;
    for(i=1;i<=num;i++)
        dig+=(log10(i)/log10(bas))*1.0;
    //cout<<dig<<endl;
    ll no=floor(dig);
    no++;
    cout<<mx<<" "<<no<<endl;
    /*for(i=0;i<len;i++)
        cout<<v[i]<<" : "<<mp[v[i]]<<endl;*/
    }
return 0;
}
