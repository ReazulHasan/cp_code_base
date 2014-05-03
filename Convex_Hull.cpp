#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

ll cross(ll x2,ll y2,ll x1,ll y1,ll x,ll y)
{
return (x1-x2)*(y-y1)-(x-x1)*(y1-y2);
}

int main()
{
//cout<<cross(0,0,5,6,10,0)<<endl;
//cout<<cross(0,0,0,10,10,10)<<endl;
int cas,i,j,k,n;
ll x,y;
char ch;
cin>>cas;
while(cas--)
    {
    int coun=0;
    pair<ll,ll> pa;
    vector<pair<ll,ll> > v;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>x>>y>>ch;
        pa.first=x;
        pa.second=y;
        if(ch=='Y')
            {
            coun++;
            v.push_back(pa);
            }
        }
    cout<<coun<<endl;
    /*for(i=0;i<coun;i++)
        cout<<v[i].first<<" "<<v[i].second<<" ";
    cout<<endl;*/
    sort(v.begin(),v.end());
    /*for(i=0;i<coun;i++)
        cout<<v[i].first<<" "<<v[i].second<<" ";
    cout<<endl;*/
    k=0;
    int len=v.size();
    vector<pair<ll,ll> > res(2*len);
    for(i=0;i<len;i++)
        {
        while(k>=2&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)<0)
            k--;
        res[k++]=v[i];
        }
    int hm=k+1;
    for(i=len-2;i>=0;i--)
        {
        while(k>=hm&&cross(res[k-2].first,res[k-2].second,res[k-1].first,res[k-1].second,v[i].first,v[i].second)<0)
            k--;
        res[k++]=v[i];
        }
    for(i=0;i<len;i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;
    /*for(i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;*/
    }
return 0;
}
