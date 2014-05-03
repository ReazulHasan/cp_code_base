#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<int,int> mp;
int a[1000],b[1000];

int seive()
{
int i,j;
for(i=2;i*i<=200;i++)
    for(j=i+i;j<=200;j+=i)
        a[j]=1;
for(i=2;i<=200;i++)
    if(a[i]==0)
        mp[i]=1;
return 0;
}

int GCD(int a,int b)
{
if(b==0)
    return a;
return GCD(b,a%b);
}

int main()
{
int n,k,i,j,a[1000],p,x,y,b[1000],m;
seive();
while(cin>>n>>k)
    {
    if(n==0&&k==0)
        break;
    p=n-k;
    if(p>k)
        {
        x=p;
        y=k;
        }
    else
        {
        x=k;
        y=p;
        }
    int m=0;
    for(i=x+1;i<=n;i++)
        a[m++]=i;
    int l=0;
    for(i=2;i<=y;i++)
        b[l++]=i;
    long long double res=1;
    int s;
    for(i=0;i<m;i++)
        if(mp[a[i]]==0)
            {
            for(j=0;j<l;j++)
                if(b[j]>1)
                    {
                    int x=GCD(a[i],b[j]);
                    if(x>1)
                        {
                        a[i]/=x;
                        b[j]/=x;
                        }
                    }
            }
    for(i=0;i<m;i++)
        res*=a[i];
    cout<<n<<" things taken "<<k<<" at a time is "<<res<<" exactly."<<endl;
    }
return 0;
}
