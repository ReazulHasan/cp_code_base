#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
double pi=2.0*acos(0.0);
double rad,a1,a2,a3,b1,b2,b3,x,y,x1,y1,x2,y2,x3,y3,p,q;
while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
    a1=y1-y2; b1=x2-x1;
    a2=y1-y3; b2=x3-x1;
    a3=y2-y3; b3=x3-x2;
    x=(a2*b1*(x1+x2)-a1*b2*(x1+x3)-a1*a2*(y2-y3))/(2*(a2*b1-a1*b2));
    y=(a2*b1*(y1+y3)+b1*b2*(x2-x3)-a1*b2*(y1+y2))/(2*(a2*b1-a1*b2));
    rad=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    double res=2*pi*rad;
    printf("%.2lf\n",res);
    }
return 0;
}
