#include<iostream>
#include<cstdio>
using namespace std;

#define sz 1000000

int a[sz+5],b[sz+5];

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
int k=1;
for(i=3;i<=sz;i++)
    if(a[i]==0)
        b[k++]=i;
return 0;
}

int prime(long long n)
{
int i;
for(i=2;i*i<=n;i++)
    if(n%i==0)
        return 0;
return 1;
}

int main()
{
seive();
//return 0;
long long n;
while(cin>>n&&n)
    {
    int x=prime(n);
    //cout<<x<<endl;
    if(x)
        cout<<n-1<<endl;
    else
        {
        long long p=n,k=0;
        for(k=0;b[k]*b[k]<=p;k++)
            {
            int f=0;
            while(p%b[k]==0)
                {
                p/=b[k];
                f=1;
                }
            if(f==1)
                {
                n/=b[k];
                n*=(b[k]-1);
                }
            }
        if(p>1)
            {
            n/=p;
            n*=(p-1);
            }
        cout<<n<<endl;
        }
    }
return 0;
}
