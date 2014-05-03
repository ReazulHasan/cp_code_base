#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
double d,res;
int a,b,t,i;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>a>>b;
    d=sqrt(a*a+b*b);
    res=(a*b)/d;
    printf("%.2lf\n",res);
    }
return 0;
}
