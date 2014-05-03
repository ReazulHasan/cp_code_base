#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

int main()
{
string str;
double s,r,theta,peta,x,pi=2.0*acos(0.0);
while(cin>>r>>theta)
    {
    cin>>str;
    r+=6440;
    if(str[0]=='m')
        theta=theta/60;
    if(theta>=180)
        s=r*(ceil(theta/360)*360-theta)*pi/180;
        //peta=ceil(theta/360)*360-theta;
    else
        {
        peta=theta;
        s=r*peta*pi/180;
        }
    x=2*r*sin((theta*pi)/360);
    if(x<0)
        {
        if(theta<=360)
            {
            if(theta>=180)
                printf("%.6lf %.6lf\n",r*(ceil(theta/360)*360-theta)*pi/180,-2*r*sin((theta*pi)/360));
            else
                printf("%.6lf %.6lf\n",r*theta*pi/180,-2*r*sin((theta*pi)/360));
            }
        else
            printf("0.000000 %.6lf\n",-2*r*sin((theta*pi)/360));
        }
    else
        {
        if(theta<=360)
            {
            if(theta>=180)
                printf("%.6lf %.6lf\n",r*(ceil(theta/360)*360-theta)*pi/180,2*r*sin((theta*pi)/360));
            else
                printf("%.6lf %.6lf\n",r*theta*pi/180,2*r*sin((theta*pi)/360));
            }
        else
            printf("0.000000 %.6lf\n",2*r*sin((theta*pi)/360));
        }
    }
return 0;
}
