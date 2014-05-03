#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
int a[100];
int i,j,t,n,p,q,m=0;
cin>>t;
while(t--)
    {
    m++;
    int x;
    cin>>n>>p>>q;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(n>p)
        x=p;
    else
        x=n;
    int coun=0,sum=0;
    for(i=0;i<x;i++)
        {
        sum+=a[i];
        if(sum>q)
            break;
        coun++;
        }
    cout<<"Case "<<m<<": "<<coun<<endl;
    }

}
