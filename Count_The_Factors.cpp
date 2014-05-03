#include<iostream>
#include<cstdio>
using namespace std;

#define sz 10000
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
for(j=3;j<=sz;j+=2)
    if(a[j]==0)
        b[k++]=j;
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
}

int factor(int n)
{
int i,j,coun=0;
for(i=0;b[i]*b[i]<=n;i++)
    {
    int fl=0;
    while(n%b[i]==0)
        {
        fl=1;
        n/=b[i];
        }
    if(fl==1)
        coun++;
    }
if(n>1)
    coun++;
return coun;
}

int main()
{
seive();
int n;
while(cin>>n&&n)
    {
    int x=factor(n);
    cout<<n<<" : "<<x<<endl;
    }
return 0;
}
