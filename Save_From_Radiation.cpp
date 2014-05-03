#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
int j,cas,kas=0;
long long n,k,i;
cin>>cas;
while(cas--)
    {
    kas++;
    cin>>n;
    k=2;
    int coun=1;
    if(n==0)
        coun=0;
    while(k<(n+1))
        {
        k*=2;
        coun++;
        }
    cout<<"Case "<<kas<<": "<<coun<<endl;
    }
return 0;
}
