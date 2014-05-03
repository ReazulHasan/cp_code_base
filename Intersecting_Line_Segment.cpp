#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

double a[2000],b[2000],c[2000],d[2000];

double direction(double x0,double y0,double x1,double y1,double x2,double y2)
{
return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int on_seg(double x0,double y0,double x1,double y1,double x2,double y2)
{
if(min(x0,x1)<=x2&&max(x0,x1)>=x2&&min(y0,y1)<=y2&&max(y0,y1)>=y2)
        return 1;
return 0;
}

int main()
{
int n,cas,i,j,k,fl=0;
double x1,y1,x2,y2,eps=0.000001;
cin>>cas;
while(cas--)
    {
    double x3,y3,x4,y4,x,y,c1,c2,m,d1,d2,d3,d4;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    int res=0;
    for(i=0;i<n;i++)
        {
        int coun=1;
        x1=a[i]; y1=b[i];
        x2=c[i]; y2=d[i];
        for(j=0;j<n;j++)
            {
            if(i!=j)
                {
                x3=a[j]; y3=b[j];
                x4=c[j]; y4=d[j];
                d1=direction(x3,y3,x4,y4,x1,y1);
                d2=direction(x3,y3,x4,y4,x2,y2);
                d3=direction(x1,y1,x2,y2,x3,y3);
                d4=direction(x1,y1,x2,y2,x4,y4);
                if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
                    coun++;
                else if(d1==0&&on_seg(x3,y3,x4,y4,x1,y1))
                    coun++;
                else if(d2==0&&on_seg(x3,y3,x4,y4,x2,y2))
                    coun++;
                else if(d3==0&&on_seg(x1,y1,x2,y2,x3,y3))
                    coun++;
                else if(d4==0&&on_seg(x1,y1,x2,y2,x4,y4))
                    coun++;
                /*c1=x1*y2-x2*y1;
                c2=x4*y3-x3*y4;
                m=(y1-y2)*(x3-x4)-(x2-x1)*(y4-y3);
                x=((x2-x1)*c2-(x3-x4)*c1)/m;
                y=((y4-y3)*c1-(y1-y2)*c2)/m;
                cout<<x<<" x y "<<y<<endl;
                if(fabs(((x-x1)*(y1-y2))-((y-y1)*(x1-x2)))<=eps&&fabs(((x-x3)*(y3-y4))-((y-y3)*(x3-x4)))<=eps)
                    {
                    cout<<fabs(((x-x1)*(y1-y2))-((y-y1)*(x1-x2)))<<" "<<fabs(((x-x3)*(y3-y4))-((y-y3)*(x3-x4)))<<endl;
                    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
                    coun++;
                    }*/
                }
            }
        //cout<<coun<<endl;
        res+=coun;
        }
    if(fl)
        cout<<endl;
    fl=1;
    cout<<res<<endl;
    }
return 0;
}
