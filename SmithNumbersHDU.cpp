#include<iostream>
#include<cstdio>
using namespace std;

#define sz 1000000
int a[sz+3],b[sz+3];

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
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
return 0;
}

int fact(int x)
{
int i,j,coun=0,fl=0;
for(i=0;b[i]*b[i]<=x;i++)
    {
    while(x%b[i]==0)
        {
        int p=b[i];
        while(p>9)
            {
            coun+=p%10;
            p/=10;
            }
        coun+=p;
        x/=b[i];
        fl=1;
        }
    //cout<<coun<<endl;
    }
if(fl==0) return 0;
if(x>1)
    {
    while(x>9)
        {
        coun+=x%10;
        x/=10;
        }
    coun+=x;
    }
return coun;
}

int main()
{
seive();
long long t,i,j,n;
while(cin>>t&&t)
    {
    //cin>>n;
    n=t;
    int sum1=0,sum2=0;
    long long x=n,p=n;
    while(1)
        {
        p++;
        x=p;
        sum1=0; sum2=0;
        while(x>9)
            {
            sum1+=x%10;
            x/=10;
            }
        sum1+=x;
        sum2=fact(p);
        //cout<<p<<" "<<sum1<<" "<<sum2<<endl;
        if(sum1==sum2)
            {
            cout<<p<<endl;
            break;
            }
        }
    }
return 0;
}
