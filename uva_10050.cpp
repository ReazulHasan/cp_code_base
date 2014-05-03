#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
int a[4000],t,n,p,i,j,m,x,k;
cin>>t;
for(k=1;k<=t;k++)
    {
    for(i=0;i<4000;i++)
            a[i]=0;
    cin>>n>>p;
    for(m=0;m<p;m++)
        {
        cin>>x;
        i=0;
        for(j=x-1;j<n;j+=x)
            if(j%7<5)
                a[j]=1;
        }
    int count=0;
        for(j=0;j<n;j++)
            if(a[j]==1)
                count++;
    cout<<count<<endl;
    }
return 0;
}
