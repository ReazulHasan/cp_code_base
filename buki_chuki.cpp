#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define sz 1000000
int a[sz+3],b[sz+3];
long long c[sz+3];
int m=1,flag=0;

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
//cout<<k<<endl;
long long p;
c[0]=0;
for(i=0;i<k;i++)
    {
    p=b[i];
    while((p*=b[i])<=1e12)    //for(p=b[i]*b[i];p<=1e12;p*=b[i])
        {
        c[m++]=p;
        }
    }
sort(c,c+m);
//cout<<m<<endl;
}

int pos(long long p)
{
long long lo=0,hi=m-1;
while(1)
    {
    int now=(lo+hi)/2;
    if(lo==now)
        {
        if(flag==0)
            return lo+1;
        else if(flag==1)
            {
            if(p>c[lo+1])
                return lo+1;
            return lo;
            }
        }
    if(p<c[now])
        hi=now;
    else if(p>c[now])
        lo=now;
    else if(p==c[now])
        return now;
    }
}

int main()
{
seive();
//return 0;
int t;
long long lo,hi;
cin>>t;
while(t--)
    {
    cin>>lo>>hi;
    flag=0;
    int x=pos(lo);
    flag=1;
    int y=pos(hi);
    if(x>y)
        cout<<"0"<<endl;
    else
        {
        int fuki=y-(x-1);
        cout<<fuki<<endl;
        }
    //cout<<x<<" "<<y<<endl;
    //int y=pos(hi);
    }
return 0;
}
