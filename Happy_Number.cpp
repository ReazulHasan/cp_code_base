#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
long long t,i,j,n;
cin>>t;
for(j=1;j<=t;j++)
    {
    int m;
    cin>>n;
    cout<<"Case #"<<j<<": "<<n;
    m=n;
    int s0=0;
    if(n>9)
        {
        while(n)
            {
            int x=n%10;
            s0+=x*x;
            n/=10;
            }
        n=s0;
        }
    else
        n*=n;
    while(n>9)
        {
        s0=0;
        while(n)
            {
            int x=n%10;
            s0+=x*x;
            n/=10;
            }
        n=s0;
        }
    if(n==1)
        cout<<" is a Happy number."<<endl;
    else
        cout<<" is an Unhappy number."<<endl;
    }
return 0;
}
