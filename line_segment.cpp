#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int min(int x,int y)
    {
    if(x<y)
        return x;
    return y;
    }

int max(int x,int y)
    {
    if(x>y)
        return x;
    return y;
    }

int direction(int xi,int yi,int xj,int yj,int xk,int yk)
    {
    return (((xk-xi)*(yj-yi))-((xj-xi)*(yk-yi)));
    }

int on_seg(int xi,int yi,int xj,int yj,int xk,int yk)
    {
    if(min(xi,xj)<=xk<=max(xi,xj)&&min(yi,yj)<=yk<=max(yi,yj))
        return 1;
    return 0;
    }

int seg_int(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
    {
    int d1,d2,d3,d4;
    d1=direction(x3,y3,x4,y4,x1,y1);
    d2=direction(x3,y3,x4,y4,x2,y2);
    d3=direction(x1,y1,x2,y2,x3,y3);
    d4=direction(x1,y1,x2,y2,x4,y4);
    if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
        return 1;
    else if(d1!=1&&on_seg(x3,y3,x4,y4,x1,y1))
        return 1;
    else if(d2!=1&&on_seg(x3,y3,x4,y4,x2,y2))
        return 1;
    else if(d3!=1&&on_seg(x1,y1,x2,y2,x3,y3))
        return 1;
    else if(d4!=1&&on_seg(x1,y1,x2,y2,x4,y4))
        return 1;
    else return 0;
    }
int main()
{
int x1,y1,x2,y2,x3,y3,x4,y4,t,i,res;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    res=seg_int(x1,y1,x2,y2,x3,y3,x4,y4);
    if(res!=0)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    }
}
