#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define maxn 1000000

int a[maxn+9];

int nod(int x)
{
int i,coun=0,mult=1;
int p=x;
for(i=2;i*i<=p;i++)
    {
    coun=0;
    while(p%i==0)
        {
        coun++;
        p/=i;
        }
    if(coun>0)
        mult*=(coun+1);
    }
if(p>1)
    mult*=2;
return mult;
}

int main()
{
int i,j,t,x,y;
a[1]=1;
for(i=2;i<=maxn;)
    {
    a[i]=1;
    int p=nod(i);
    //cout<<i<<" "<<p<<endl;;
    i=i+p;
    }
for(j=2;j<=maxn;j++)
    a[j]=a[j]+a[j-1];
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x>>y;
    cout<<"Case "<<i<<": "<<a[y]-a[x-1]<<endl;
    }
return 0;
}
