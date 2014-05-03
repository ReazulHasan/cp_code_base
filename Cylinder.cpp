#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
double w,h,r,area1,pi=2.0*acos(0.0),lo,hi,mid,rlo,rhi,peri,area2,res;
while(cin>>w>>h)
    {
    if(w==0&&h==0)
        break;
    r=w/(2*pi);
    lo=0; hi=h;
    while(1)
        {
        mid=(lo+hi)/2.0;
        peri=h-mid;
        rlo=mid/2.0;
        rhi=peri/(2.0*pi);
        if(fabs(rhi-rlo)<=0.0000000001)
            break;
        if(rhi<rlo)
            hi=mid;
        else
            lo=mid;
        }
    //cout<<r<<" "<<rhi<<" "<<rlo<<endl;
    /*if((2*r)>(h-2*r))
        r=(h-2*r)/2.0;*/
    area1=pi*r*r*(h-2*r);
    if((2*rhi)>w)
        rhi=w/2.0;
    area2=pi*rhi*rhi*w;
    //cout<<area1<<" "<<area2<<endl;
    if(area1>area2)
        res=area1;
    else
        res=area2;
    printf("%.3lf\n",res);
    }
return 0;
}
