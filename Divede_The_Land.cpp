#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int t,i,j,k,cas=0;
double mid,ar,h,tri,s,bas,a,b,c,d,hi,lo,hit,bas1,trap;
cin>>t;
while(t--)
    {
    cas++;
    cin>>a>>b>>c>>d;
    bas=a-b;
    s=(c+d+bas)/2;
    tri=sqrt(s*(s-c)*(s-d)*(s-bas));
    h=(2*tri)/bas;
    ar=((a+b)*h)/4.0;
    lo=0; hi=h;
    while(1)
        {
        mid=(lo+hi)/2.0;
        bas1=(bas*mid)/h;
        trap=((b+b+bas1)*mid)/2.0;
        //cout<<trap<<endl;
        if(fabs(trap-ar)<=0.000001)
            break;
        if(trap>ar)
            hi=mid;
        else
            lo=mid;
        }
    double x,y;
    x=c-(c*bas1)/bas;
    y=d-(d*bas1)/bas;
    printf("Land #%d: %.6lf %.6lf\n",cas,x,y);
    }
return 0;
}
