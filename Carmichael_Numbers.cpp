#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define maxn 65000

int a[maxn+3],b[maxn+3],k,farm[maxn+3];
map<int,int> mp;

int seive()
{
int i,j,p;
for(i=2;i*i<=maxn;)
    {
    for(j=i+i;j<=maxn;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
cout<<"hi"<<endl;
for(i=2;i<=maxn;i++)
    {
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
    else
        {
        int n=i;
            int flag=0;
        unsigned long long a=1;
        //b=n;
        for(j=2;j<n;j++)
            {
            a=1;
            for(p=1;p<=n;p++)
                {
                a*=j;
                a%=n;
                }
            if(a%n!=j)
                {
                flag=1;
                break;
                }
            /*else
                {
                flag=0;
                break;
                }*/
            a=1;
            }
        if(flag==0)
            farm[n]=1;
        }
    }
for(i=0;i<maxn;i++)
    if(farm[i]==1)
        cout<<i<<endl;
return 0;
//cout<<mp[341];
}

int main()
{
seive();
int n,b,i,j;
while(cin>>n&&n)
    {
    /*int flag=0;
    unsigned long long a=1;
    b=n;
    for(j=2;j<n;j++)
        {
        a=1;
        for(i=1;i<=n;i++)
            {
            a*=j;
            a%=n;
            }
        if(a%b==j)
            flag=1;
        else
            {
            flag=0;
            break;
            }
        a=1;
        }*/
    /*if(flag==1)
        {
        if(mp[b]==1)
            cout<<b<<" is normal."<<endl;
        else
            cout<<"The number "<<b<<" is a Carmichael number."<<endl;
        }
    else
        cout<<b<<" is normal."<<endl;*/
    }
return 0;
}
