#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

#define eps 0.00000000001

int main()
{
int i,j,k;
double p,q,r,s,t,u,hi,lo,mid,now_mid,now_lo,now_hi,x,res1,res0;
while(cin>>p>>q>>r>>s>>t>>u)
    {
    hi=1; lo=0;
    x=1;
    res1=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
    x=0;
    res0=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
    if(res1>eps&&res0>eps)
        cout<<"No solution"<<endl;
    else if(res1<eps&&res0<eps)
        cout<<"No solution"<<endl;
    else if(res1<eps&&res1>-eps)
        cout<<"1.0000"<<endl;
    else if(res0<eps&&res0>-eps)
        cout<<"0.0000"<<endl;
    else
    while(1)
        {
        mid=(hi+lo)/2;
        x=mid;
        now_mid=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
        if(now_mid<eps&&now_mid>-eps)
            {
            //cout<<"now_mid: "<<now_mid<<endl;
            printf("%.4llf\n",x);
            break;
            }
        x=hi;
        now_hi=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
        x=lo;
        now_lo=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
        if((now_lo-now_mid)>eps)
            lo=mid;
        else
            hi=mid;
        cout<<now_hi<<" "<<now_mid<<" "<<now_lo<<endl;
        //break;
        }
    }
return 0;
}
