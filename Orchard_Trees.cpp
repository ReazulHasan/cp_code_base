#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
double xm,ym,x0,y0,x1,y1,x2,y2,a1,a2,a3,a;
while(cin>>x0>>y0>>x1>>y1>>x2>>y2)
    {
    if(x1==0&&y1==0&&x2==0&&y2==0&&x0==0&&y0==0)
        break;
    int coun=0;
    a=x0*y1+x1*y2+x2*y0-x0*y2-x2*y1-x1*y0;
    if(a<0.0)
        a*=-1;
    for(i=1;i<100;i++)
        {
        int flag=0;
        for(j=1;j<100;j++)
            {
            int fl=0;
            xm=i*1.0; ym=j*1.0;
            if(a==0)
                {
                int f=1;
                //if(xm==1&&ym==1)
                    //cout<<fabs((xm-x0)*(y0-y1)-(ym-y0)*(x0-x1))<<endl;
                if(fabs((xm-x1)*(y1-y2)-(ym-y1)*(x1-x2))<=0.0000000001&&((xm>=x1&&xm<=x2)||(xm<=x1&&xm>=x2))&&((ym>=y1&&ym<=y2)||(ym<=y1&&ym>=y2)))
                    {
                    //if(((xm>=x1&&xm<=x2)||(xm<=x1&&xm>=x2))&&((ym>=y1&&ym<=y2)||(ym<=y1&&ym>=y2)))
                        {
                        coun++;
                        flag=1; fl=1; f=0;
                        //cout<<"1 "<<xm<<" "<<ym<<endl;
                        }
                    }
                else if(fabs((xm-x0)*(y0-y1)-(ym-y0)*(x0-x1))<=0.0000000001&&((xm>=x0&&xm<=x1)||(xm<=x0&&xm>=x1))&&((ym>=y0&&ym<=y1)||(ym<=y0&&ym>=y1)))
                    {
                    //if(((xm>=x0&&xm<=x1)||(xm<=x0&&xm>=x1))&&((ym>=y0&&ym<=y1)||(ym<=y0&&ym>=y1)))
                        {
                        coun++;
                        flag=1; fl=1; f=0;
                        //cout<<"2 "<<xm<<" "<<ym<<endl;
                        }
                    }
                else if(fabs((xm-x0)*(y0-y2)-(ym-y0)*(x0-x2))<=0.0000000001&&((xm>=x0&&xm<=x2)||(xm<=x0&&xm>=x2))&&((ym>=y0&&ym<=y2)||(ym<=y0&&ym>=y2)))
                    {
                    //if(((xm>=x0&&xm<=x2)||(xm<=x0&&xm>=x2))&&((ym>=y0&&ym<=y2)||(ym<=y0&&ym>=y2)))
                        {
                        coun++;
                        flag=1; fl=1; f=0;
                        //cout<<"3 "<<xm<<" "<<ym<<endl;
                        }
                    }
                }
            else
                {
                a1=x0*y1+x1*ym+xm*y0-x0*ym-xm*y1-x1*y0;
                if(a1<0)
                    a1*=-1;
                a2=x0*y2+x2*ym+xm*y0-x0*ym-xm*y2-x2*y0;
                if(a2<0)
                    a2*=-1;
                a3=x1*y2+x2*ym+xm*y1-xm*y2-x1*ym-x2*y1;
                if(a3<0)
                    a3*=-1;
                if(fabs(a-(a1+a2+a3))<=0.000000001)
                    {
                    //cout<<a<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
                    coun++;
                    flag=1; fl=1;
                    //cout<<i<<" "<<j<<endl;
                    }
                }
            //if(flag&&fl)
                //cout<<xm<<" "<<ym<<endl;
            if(flag&&fl==0)
                break;
            }
        }
    printf("%4d\n",coun);
    //cout<<coun<<endl;
    }
return 0;
}
