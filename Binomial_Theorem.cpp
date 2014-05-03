#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;

ll n;
vector<ll> hi,lo;

ll gcd(ll a,ll b)
{
if(b==0)
    return a;
return gcd(b,a%b);
}

ll binomial(int r)
{
hi.clear();
lo.clear();
ll i,j,k,n_r=n-r;
if(n==r)
    return 1;
if(r<n_r)
    {
    ll tmp=r;
    r=n_r;
    n_r=tmp;
    }
for(i=r+1;i<=n;i++)
    hi.push_back(i);
for(i=2;i<=n_r;i++)
    lo.push_back(i);
ll len1=hi.size(),len2=lo.size();
for(i=0;i<len1;i++)
    for(j=0;j<len2;j++)
        {
        ll x=gcd(hi[i],lo[j]);
        if(x>1)
            {
            hi[i]/=x;
            lo[j]/=x;
            }
        }
ll up=1,down=1;
for(i=0;i<len1;i++)
    up*=hi[i];
for(j=0;j<len2;j++)
    down*=lo[j];
return up/down;
}

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
while(cas--)
    {
    kas++;
    string s,s1,s2;
    cin>>s;
    int len=s.size();
    ll num=0;
    for(i=1;s[i]!='+';i++)
        s1+=s[i];
    for(j=i+1;s[j]!=')';j++)
        s2+=s[j];
    for(i=j+2;i<len;i++)
        {
        num*=10;
        num+=s[i]-'0';
        }
    n=num;
    cout<<"Case "<<kas<<": ";
    cout<<s1;
    if(n>1)
        cout<<"^"<<n;
    if(n==0)
        n=1;
    for(i=1;i<=n;i++)
        {
        cout<<"+";
        ll x=binomial(i);
        if(x>1)
            cout<<x<<"*";
        if((n-i)>0)
            cout<<s1;
        if((n-i)>1)
            cout<<"^"<<n-i;
        if((n-i)>0)
            cout<<"*";
        cout<<s2;
        if(i>1)
            cout<<"^"<<i;
        }
    cout<<endl;
    //cout<<s1<<" "<<s2<<" "<<num<<endl;
    }
return 0;
}
