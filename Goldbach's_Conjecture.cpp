#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define max 1000000

int a[max+9],b[max+9];
map<int,int> mp;

int seive()
{
int i,j,k=0;
for(i=2;i*i<=max;i++)
    for(j=i+i;j<=max;j+=i)
        a[j]=1;
for(i=2;i<=max;i++)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
return 0;
}

int main()
{
int i,j,n;
seive();
//cout<<mp[999983]<<endl;
while(cin>>n&&n)
    {
    int x,flag=0;
    for(i=0;i<=n/2;i++)
        {
        x=n-b[i];
        if(mp[x]==1)
            break;
        if(b[i]>=n)
            {
            flag=1;
            cout<<"Goldbach's conjecture is wrong."<<endl;
            }
        }
    if(flag==0)
        cout<<n<<" = "<<n-x<<" + "<<x<<endl;
    }
return 0;
}
