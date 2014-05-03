#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
int t,n,i,j,a[10009],coun=0;
cin>>t;
while(t--)
    {
    coun++;
    cin>>n;
    if(n>0)
        {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<"Case "<<coun<<": "<<a[n-1]<<endl;
        }
    }
return 0;
}
