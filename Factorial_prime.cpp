            //it is the code for "FACTORIAL FACTORS".

#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

#define max 1000000

int a[max+9],b[max+9],res[max+9];
map<int,int> mp;

int seive()
{
int i,j,k;
for(i=2;i*i<=max;)
    {
    for(j=i+i;j<=max;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
k=1;
b[0]=2;
mp[2]=1;
for(i=3;i<=max;i+=2)
    if(a[i]==0)
        {
        mp[i]=1;
        b[k++]=i;
        }
/*for(i=0;i<k;i++)
    cout<<b[i]<<" ";*/
}

int precalc()
{
int i,j,k;
for(i=2;i<=max;i++)
    {
    int x=i;
    if(mp[x]==1)
        res[x]=1;
    else
        {
        if(x%2==0)
            res[i]=res[x/2]+1;
        else
            {
            for(j=0;b[j]*b[j]<=x;j++)
                if(x%b[j]==0)
                    res[i]=res[x/b[j]]+1;
            }
        }
    }
int sum=0;
for(i=2;i<=max;i++)
    res[i]+=res[i-1];
return 0;
}

int main()
{
int n;
seive();
precalc();
while(cin>>n)
    cout<<res[n]<<endl;
return 0;
}
