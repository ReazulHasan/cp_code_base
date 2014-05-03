#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
double pi=2.0*acos(0.0);
double s,a,b,c,area,inr,cirr,inar,cirar;
while(cin>>a>>b>>c)
    {
    s=(a+b+c)/2.0;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    inr=area/s;
    cirr=(a*b*c)/(4*area);
    inar=pi*inr*inr;
    cirar=pi*cirr*cirr;
    printf("%.4lf %.4lf %.4lf\n",cirar-area,area-inar,inar);
    }
return 0;
}
