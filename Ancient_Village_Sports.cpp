#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
int i,j,k=0;
double n,area,pi=2.0*acos(0.0);
while(cin>>n>>area)
    {
    k++;
    if(n<3)
        break;
    double inrad,cirrad,inar,cirar;
    inrad=sqrt(area/(n*tan(pi/n)));
    cirrad=sqrt((2*area)/(n*sin((2*pi)/n)));
    inar=pi*inrad*inrad;
    cirar=pi*cirrad*cirrad;
    inar=area-inar;
    cirar=cirar-area;
    printf("Case %d: %.5lf %.5lf\n",k,cirar,inar);
    //cout<<inar<<" "<<cirar<<endl;
    }
return 0;
}
