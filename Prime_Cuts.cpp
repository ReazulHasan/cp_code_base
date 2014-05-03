#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define max 1200

int a[max+5],b[max+5];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=max;i++)
    for(j=i+i;j<=max;j+=i)
        a[j]=1;
b[0]=1;
b[1]=2;
int t=1;
mp[1]=t++;
mp[2]=t++;
int k=2;
for(i=3;i<=max;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=t++;
        }
/*for(i=0;i<k;i++)
    cout<<b[i]<<" ";*/
return 0;
}

int main()
{
int n,k,i,j;
seive();
while(cin>>n>>k)
    {
    int x;
    cout<<n<<" "<<k<<":";
    while(mp[n]==0)
        n--;
    x=mp[n];
    if(x%2==0)
        k*=2;
    else
        {
        k*=2;
        k--;
        }
    if(k>=x)
        for(i=0;i<x;i++)
            cout<<" "<<b[i];
    else
        {
        int bad=x-k;
        bad/=2;
        for(i=bad;i<(bad+k);i++)
            cout<<" "<<b[i];
        }
    cout<<endl<<endl;
    }
return 0;
}
