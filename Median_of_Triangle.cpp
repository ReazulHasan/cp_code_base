#include<iostream>
#include<cmath>
using namespace std;

main()
{
    double a,b,c,d,e,f,g,h,s,area;
    while(cin>>a>>b>>c)
    {
        s=0.5*(a+b+c);
        d=s*(s-a)*(s-b)*(s-c);
        area=(4.0*sqrt(d))/3.0;
        if(d>0)
        printf("%.3lf\n",area);
        else
        printf("-1.000\n");
    }
    return 0;
}
