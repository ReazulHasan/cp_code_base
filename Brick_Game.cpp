#include<iostream>
using namespace std;

int main()
{
int a[10000],t,i,n,coun=0;
cin>>t;
while(t--)
    {
    coun++;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    n/=2;
    cout<<"Case "<<coun<<": "<<a[n]<<endl;
    }
return 0;
}
