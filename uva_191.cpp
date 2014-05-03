#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

seg_int(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
int d1,d2,d3,d4;
d1=direction(x3,y3,x4,y4,x1,y1);
d2=direction(x3,y3,x4,y4,x2,y2);
d3=direction(x1,y1,x2,y2,x3,y3);
d4=direction(x1,y1,x2,y2,x4,y4);

if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
    return 1;
else if(d1!<0&&d1!>0&&on_seg())
}

int main()
{
int t,i,p,q,r,s,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    x5=x3; y5=y4; x6=x4; y6=y3;
    p=seg_int(x1,y1,x2,y2,x3,y3,x5,y5)
    q=seg_int(x1,y1,x2,y2,x4,y4,x5,y5)
    r=seg_int(x1,y1,x2,y2,x4,y4,x6,y6)
    s=seg_int(x1,y1,x2,y2,x3,y3,x6,y6)
    }
}
