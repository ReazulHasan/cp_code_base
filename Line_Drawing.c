#include<stdio.h>
#include<math.h>
//#include<graphics.h>
#include<stdlib.h>
#include<g2++.h>
#include<g2_X11++.h>

int midpoint_algo(int x1,int y1,int x2,int y2)
{
int dy,dx,incE,incNE,x,y,d,temp,slope;
if(x1>x2)
    {
    temp=x1;
    x1=x2;
    x2=temp;
    temp=y1;
    y1=y2;
    y2=temp;
    }
dy=y2-y1;
dx=x2-x1;
if(dy<0)
    {
    slope=-1;
    dy*=-1;
    }
else
    slope=1;
d=2*dy-dx;
incE=2*dy;
incNE=2*dy-2*dx;
y=y1;
for(x=x1;x<=x2;x++)
    {
    putpixel(x,y,WHITE);
    if(d<=0)
        d+=incE;
    else
        {
        d+=incNE;
        y+=slope;
        }
    }
}

int main()
{
int x1,y1,x2,y2;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
midpoint_algo(x1,y1,x2,y2);
return 0;
}
