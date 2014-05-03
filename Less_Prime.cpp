#include<iostream>
#include<cstdio>
using namespace std;

#define sz 50000
int a[sz+3],b[sz+3];
int k=0;

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
k=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
}

int main()
{
seive();
int t,i,j,n;
cin>>t;
while(t--)
    {
    cin>>n;
    n/=2;
    for(i=0;i<k;i++)
        if(b[i]>n)
            {
            cout<<b[i]<<endl;
            break;
            }
    }
return 0;
}
