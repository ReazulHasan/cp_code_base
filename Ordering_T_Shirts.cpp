#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int a[100];
long long fact[100],fin=0,now=1,res[100];

int factorial(int n)
{
int i,j;
long long x=1;
for(i=1;i<=n;i++)
    x*=i;
return x;
}

int recur(int pos,int n)
{
int i,j,k;
if((pos)==n)
    {
    now=fact[n+1];
    int coun=0;
    for(i=0;i<n;i++)
        {
        //cout<<a[i];
        if(a[i]==0)
            {
            coun=0;
            while(a[i]==0&&i<n)
                {
                coun++;
                i++;
                }
            now/=fact[coun+1];
            }
        }
    //cout<<endl;
    fin+=now;
    return 0;
    }
a[pos]=0;
recur(pos+1,n);
a[pos]=1;
recur(pos+1,n);
}

int main()
{
int i,j,k;
for(i=1;i<12;i++)
    fact[i]=factorial(i);
for(i=0;i<11;i++)
    {
    fin=0;
    recur(0,i);
    //cout<<fin<<endl;
    res[i+1]=fin;
    }
int t;
cin>>t;
while(t--)
    {
    int m;
    cin>>m;
    cout<<res[m]<<endl;
    }
return 0;
}
