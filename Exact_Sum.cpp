#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
int a[10000],i,j,n,x;
map<int,int> mp;
while(cin>>n)
    {
    for(i=0;i<n;i++)
        {
        cin>>j;
        mp[j]++;
        a[i]=j;
        }
    cin>>x;
    sort(a,a+n);
    int p=1,q=1;
    for(i=0;a[i]<=x/2;i++)
        {
        int it=x-a[i];
        if(mp[it]>0&&a[i]<x/2)
            {
            p=a[i];
            q=it;
            }
    if(it==x/2)
        if(mp[it]>1)
            {
            p=a[i];
            q=it;
            }
      //cout<<p<<" "<<q<<endl;
        }
    cout<<"Peter should buy books whose prices are "<<p<<" and "<<q<<"."<<endl;
    cout<<endl;
    mp.clear();
    for(i=0;i<n;i++)
        a[i]=0;
    }
return 0;
}
