#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
int t,n,k,p,i,j,a;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>n>>k>>p;
    a=k+p;
    if(a==n||(a%n==0)) cout<<"Case "<<i<<": "<<n<<endl;
    else
        cout<<"Case "<<i<<": "<<a%n<<endl;
    }
}
