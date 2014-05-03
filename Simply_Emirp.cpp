#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define size 2000000

int a[size],b[size];
map<int,int> mp,mp1;

int seive()
{
int i,j;
for(i=2;i*i<=size;)
    {
    for(j=i+i;j<=size;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
mp[2]=1;
int k=1;
for(i=3;i<=size;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
for(i=0;i<k;i++)
    {
    int rev=0;
    int it=b[i];
    while(it>9)
        {
        rev*=10;
        rev+=it%10;
        it/=10;
        }
    rev*=10;
    rev+=it;
    if(rev!=b[i])
        if(mp[rev]==1)
            mp1[b[i]]=1;
    //cout<<rev<<" ";
    }
}

int main()
{
seive();
int n;
while(cin>>n)
    {
    if(mp[n]==1&&mp1[n]==1)
        cout<<n<<" is emirp."<<endl;
    else if(mp[n]==1&&mp1[n]==0)
        cout<<n<<" is prime."<<endl;
    else
        cout<<n<<" is not prime."<<endl;
    }
return 0;
}
