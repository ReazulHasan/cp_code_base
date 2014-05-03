#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

double eps=0.0000001;

int main()
{
int i,j,k,t;
double dis,rop;
double pi=2.0*acos(0.0);
cin>>t;
while(t--)
    {
    cin>>dis>>rop;
    double ext=rop-dis;
    double besi=(ext/2)*1.0;
    double bas=(dis/2)*(1.0);
    double hyp=(rop/2)*(1.0);
    double per=sqrt(hyp*hyp-bas*bas);
    bas+=besi;
    double ellipse=pi*bas*per;
    ellipse+=eps;
    printf("%.3lf\n",ellipse);
   // cout<<ellipse<<endl;
    }
return 0;
}
