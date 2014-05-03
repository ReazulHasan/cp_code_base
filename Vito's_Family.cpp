#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
int a[10000];
int t,n,i,j,k;
while(cin>>t)
    {
    for(k=0;k<t;k++)
        {
        cin>>n;
        for(j=0;j<n;j++)
            cin>>a[j];
    sort(a,a+n);
    int med;
    if(n%2==1)
        med=a[n/2];
    else
        med=a[n/2];
    //cout<<med<<endl;
    int res=0;
    for(i=0;i<n;i++)
        {
        if(med>a[i])
            res+=(med-a[i]);
        else
            res+=(a[i]-med);
        }
        cout<<res<<endl;
        }
    }
return 0;
}
