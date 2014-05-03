#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
double a,b,c,p,q,r,x,y,z;
while(cin>>p>>q>>r)
    {
    if(p<=0||q<=0||r<=0)
        cout<<"-1.000"<<endl;
    else
        {
        a=p*p; b=q*q; c=r*r;
        if((8*a+8*b)<=4*c||(8*b+8*c)<=4*a||(8*c+8*a)<=4*b)
            cout<<"-1.000"<<endl;
        else
            {
            x=sqrt((8*p*p)+(8*q*q)-(4*r*r))/3;
            y=sqrt((8*p*p)+(8*r*r)-(4*q*q))/3;
            z=sqrt((8*q*q)+(8*r*r)-(4*p*p))/3;
            if((x+y)<z||(y+z)<x||(z+x)<y)
                cout<<"-1.000"<<endl;
            else
                {
                double s=(x+y+z)/2;
                double tri=sqrt(s*(s-x)*(s-y)*(s-z));
                printf("%.3lf\n",tri);
                }
            }
        }
    }
return 0;
}
