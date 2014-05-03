#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
double l,w,h,theta,x;
while(cin>>l>>w>>h>>theta)
    {
    x=l*tan(theta);
    double tri=(l*x)/2;
    double rect=l*w*h;
    double res=rect-tri;
    printf("%.3lf\n",res);
    }
return 0;
}
