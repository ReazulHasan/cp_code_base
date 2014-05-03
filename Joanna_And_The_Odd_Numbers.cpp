#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
unsigned long long n,x,res;
while(cin>>n)
    {
    x=(n+1)/2;
    x*=x;
    res=(x*x)-((x-3)*(x-3));
    cout<<res<<endl;
    }
return 0;
}
