#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
double n,p;
while(cin>>n>>p)
    {
    double x=pow(p,1/n);
    printf("%.0lf\n",x);
    //cout<<x<<endl;
    }
return 0;
}
