#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<map>
typedef long long ll;
using namespace std;

ll a[100];

int main()
{
int i,j,k,cas;
ll fact=1;
a[0]=1;
a[1]=1;
for(i=2;i<=12;i++)
    {
    fact=1;
    for(j=1;j<=i;j++)
        fact*=j;
    a[i]=fact;
    }
/*for(i=0;i<=12;i++)
    cout<<a[i]<<endl;*/
cin>>cas;
while(cas--)
    {
    int n;
    cin>>n;
    ll res=a[n];
    for(i=1;i<=n;i++)
        {
        if(i%2)
            res-=a[n]/a[i];
        else
            res+=a[n]/a[i];
        }
    cout<<res<<"/"<<a[n]<<endl;
    }
return 0;
}
