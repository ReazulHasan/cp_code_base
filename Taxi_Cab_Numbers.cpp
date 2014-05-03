#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define sz 1000
vector<long long> v,vres;
map<long long,long long> mp,mpflag;

int cubes()
{
long long i,j;
for(i=1;i<=sz;i++)
    {
    long long x=i*i*i;
    v.push_back(x);
    }
int len=v.size();
for(i=0;i<len;i++)
    {
    for(j=i;j<len;j++)
        {
        long long p=v[i]+v[j];
        mpflag[p]++;
        if(mpflag[p]>=2&&mp[p]==0)
            {
            vres.push_back(p);
            mp[p]=1;
            }
        }
    }
sort(vres.begin(),vres.end());
/*long long ln=vres.size();
cout<<ln<<endl;
int c=0;
for(i=0;i<ln;i++)
    {
    cout<<vres[i]<<" ";
    if(vres[i]<=1001000000)
        c++;
    }
cout<<endl;
cout<<c<<endl;*/
return 0;
}

int main()
{
cubes();
//return 0;
vector<long long>::iterator t1,t2;
long long i,j,lo,rang;
long long len=v.size();
while(cin>>lo>>rang)
    {
    long long hi=lo+rang;
    t1=lower_bound(vres.begin(),vres.end(),lo);
    t2=upper_bound(vres.begin(),vres.end(),hi);
    long long x=t1-vres.begin();
    long long y=t2-vres.begin();
    //cout<<x<<" "<<y<<endl;
    if(x==y)
        cout<<"None"<<endl;
    for(i=x;i<y;i++)
        cout<<vres[i]<<endl;
    }
return 0;
}
