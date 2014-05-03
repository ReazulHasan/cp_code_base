#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
int t,i,year,pi=3.1416,res;
double x,y,area,r;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x>>y;
    r=(x*x)+(y*y);
    area=(pi*r)/100;
    cout<<area<<endl;
    res=area;
    cout<<res<<endl;
    cout<<"Property "<<i<<": This property will begin eroding in year "<<res+1<<"."<<endl;
    if(i==t)
        cout<<"END OF OUTPUT.";
    }
}
