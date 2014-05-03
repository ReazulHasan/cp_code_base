#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
double ax,ay,bx,by,cx,cy,px,py,qx,qy,rx,ry,fx,fy,ex,ey,dx,dy,area;
int cas;
cin>>cas;
while(cas--)
    {
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    dx=(cx+2*bx)/3; dy=(cy+2*by)/3;
    ex=(ax+2*cx)/3; ey=(ay+2*cy)/3;
    fx=(bx+2*ax)/3; fy=(by+2*ay)/3;
    //cout<<dx<<" "<<dy<<" "<<ex<<" "<<ey<<" "<<fx<<" "<<fy<<endl;
    ry=((ay*dx-ax*dy)*(cy-fy)+(cx*fy-cy*fx)*(ay-dy))/((cx-fx)*(ay-dy)-(ax-dx)*(cy-fy));
    rx=(ry*(cx-fx)-(cx*fy-cy*fx))/(cy-fy);
    qy=((by*ex-bx*ey)*(cy-fy)+(by-ey)*(cx*fy-cy*fx))/((cx-fx)*(by-ey)-(bx-ex)*(cy-fy));
    qx=(qy*(cx-fx)-(cx*fy-cy*fx))/(cy-fy);
    py=((ay*dx-ax*dy)*(by-ey)-(by*ex-bx*ey)*(ay-dy))/((bx-ex)*(ay-dy)-(ax-dx)*(by-ey));
    px=(py*(bx-ex)+(by*ex-bx*ey))/(by-ey);
    //cout<<qx<<" "<<qy<<" "<<px<<" "<<py<<" "<<rx<<" "<<ry<<endl;
    area=(px*qy+qx*ry+rx*py-px*ry-rx*qy-qx*py)/2;
    if(area<0)
        area*=-1;
    printf("%.0lf\n",area);
    }
return 0;
}
