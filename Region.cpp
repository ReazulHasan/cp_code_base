#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int t,i,j,k;
double pi=(2.0)*acos(0.0);
double eps=0.00000001;
//cout<<pi<<endl;
double r1,r2,r3;
cin>>t;
while(t--)
    {
    double a,b,c,peri,tri,rega,regb,regc;
    cin>>r1>>r2>>r3;
    a=r1+r2; b=r2+r3; c=r3+r1;
    //a=30; b=28; c=26;
    peri=(a+b+c)/2;
    tri=sqrt(peri*(peri-a)*(peri-b)*(peri-c));
    //cout<<peri<<" "<<tri<<endl;
    rega=(r3*r3*(acos((b*b+c*c-a*a)/(2*b*c))))/2;
    regb=(r1*r1*(acos((a*a+c*c-b*b)/(2*a*c))))/2;
    regc=(r2*r2*(acos((a*a+b*b-c*c)/(2*a*b))))/2;
    //cout<<rega<<" "<<regb<<" "<<regc<<endl;
    double x=rega+regb+regc;
    //cout<<x<<endl;
    double res=tri-x;
    res+=eps;
    printf("%.6lf\n",res);
    }
return 0;
}
