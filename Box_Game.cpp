#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main()
{
int i,j,k;
long long n=1;
map<long long,int> mp;
int coun=0;
while(coun<33)
    {
    n=1;
    coun++;
    for(i=1;i<=coun;i++)
        n*=2;
    mp[n-1]=1;
    }
while(cin>>k&&k)
    {
    if(mp[k]==1)
        cout<<"Bob"<<endl;
    else
        cout<<"Alice"<<endl;
    }
return 0;
}
