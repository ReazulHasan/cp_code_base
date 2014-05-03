#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,n,cas;
long long a[30009];
cin>>cas;
while(cas--)
    {
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long res=0;
    for(i=n-3;i>=0;i-=3)
        res+=a[i];
    cout<<res<<endl;
    }
return 0;
}
