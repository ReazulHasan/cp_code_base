#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define size 1000000

int a[size],b[size];
map<int,int> mp;

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
}

int main()
{
seive();
int n,i;
while(cin>>n&&n)
    {
    int flag=0;
    cout<<n<<":"<<endl;
    for(i=0;b[i]<=n/2;)
        {
        int x=n-b[i];
        if(mp[x]==1)
            {
            flag=1;
            cout<<b[i]<<"+"<<x<<endl;
            break;
            }
        i++;
        }
    if(flag==0)
        cout<<"NO WAY!"<<endl;
    }
return 0;
}
