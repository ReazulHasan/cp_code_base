#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
double rad,m1,n1,m2,n2,m3,n3,x,y,z,a,b,c,s,area;
int cas;
cin>>cas;
while(cas--)
    {
    cin>>rad>>m1>>n1>>m2>>n2>>m3>>n3;
    x=(rad/n1)*sqrt((m1*m2+m2*n1+n1*n2)/(m1*n2));
    y=(rad/m2)*sqrt((m2*n1+n2*n1+m1*m2)/(m1*n2));
    z=(rad/n3)*sqrt((m1*m3+m1*n3+n1*n3)/(m3*n1));
    c=m1*x+n1*x;
    a=m2*y+n2*y;
    b=m3*z+n3*z;
    s=(a+b+c)/2.0;
    area=rad*s;
    printf("%.4lf\n",area);
    }
return 0;
}
