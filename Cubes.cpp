#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define sz 1000

vector<long long> v;
map<long long,long long> mpya,mpit;

int cubes()
{
long long i,j;
for(i=0;i<=sz;i++)
    {
    long long x;
    x=i*i*i;
    v.push_back(x);
    mpya[x]=i;
    mpit[i]=x;
    }
return 0;
}

int main()
{
cubes();
long long i,j,n;
long long len=v.size();
while(cin>>n&&n)
    {
    int flag=0;
    for(i=0;i<len;i++)
        {
        long long x=n+v[i];
        if(mpya[x]>0)
            {
            long long now=mpya[x];
            cout<<now<<" "<<i<<endl;
            flag=1;
            break;
            }
        }
    if(flag==0)
        cout<<"No solution"<<endl;
    }
return 0;
}
