#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
double rad,a1,a2,a3,b1,b2,b3,x,y,x1,y1,x2,y2,x3,y3,p,q;
while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
    a1=y1-y2; b1=x2-x1;
    a2=y1-y3; b2=x3-x1;
    a3=y2-y3; b3=x3-x2;
    x=(a2*b1*(x1+x2)-a1*b2*(x1+x3)-a1*a2*(y2-y3))/(2*(a2*b1-a1*b2));
    y=(a2*b1*(y1+y3)+b1*b2*(x2-x3)-a1*b2*(y1+y2))/(2*(a2*b1-a1*b2));
    rad=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    //printf("%.3lf %.3lf\n",x,y);
    cout<<"(x ";
    if(x<0)
        {
        cout<<"+ ";
        p=-x;
        }
    else
        {
        cout<<"- ";
        p=x;
        }
    printf("%.3lf)^2 + (y ",p);
    if(y<0)
        {
        cout<<"+ ";
        q=-y;
        }
    else
        {
        cout<<"- ";
        q=y;
        }
    printf("%.3lf)^2 = %.3lf^2\n",q,rad);
    cout<<"x^2 + y^2 ";
    double g,f,c;
    g=2*x; f=2*y;
    c=(x*x)+(y*y)-(rad*rad);
    if(g<0)
        {
        cout<<"+ ";
        p=-g;
        }
    else
        {
        cout<<"- ";
        p=g;
        }
    printf("%.3lfx ",p);
    if(f<0)
        {
        cout<<"+ ";
        q=-f;
        }
    else
        {
        cout<<"- ";
        q=f;
        }
    printf("%.3lfy ",q);
    if(c<0)
        {
        cout<<"- ";
        c*=-1;
        }
    else
        cout<<"+ ";
    printf("%.3lf = 0\n\n",c);
    }
return 0;
}
