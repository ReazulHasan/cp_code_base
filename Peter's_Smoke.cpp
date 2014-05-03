#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
int n,k,i,j;
while(cin>>n>>k)
    {
    int sum=n,rest=0;
    while(n>=k)
        {
        sum+=n/k;
        rest=n%k;
        n/=k;
        n+=rest;
        //cout<<n<<endl;
        }
    cout<<sum<<endl;
    }
return 0;
}
