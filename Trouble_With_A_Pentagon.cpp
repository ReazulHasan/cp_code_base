#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
double pent,sq,r,pi=2.0*acos(0.0);
double R=(54*pi)/180,A=72;
cout<<cos(R)<<endl;
while(cin>>pent)
    {
    //r=pent*sin(R)/sin(A);
    r=pent/(2*cos(R));
    sq=sqrt(r*r+r*r);
    printf("%.10lf\n",sq);
    }
return 0;
}
