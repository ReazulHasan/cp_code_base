#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
long long i,j,k,a=1,b=2,c;
for(i=1;i<=50;i++)
    {
    c=a+b;
    a=b;
    b=c;
    }
cout<<c<<endl;
return 0;
}
