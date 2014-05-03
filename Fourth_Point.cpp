#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k;
double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,midx,midy;
while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
    if(x1==x3&&y1==y3)
        {
        x5=x1; y5=y1;
        midx=(x2+x4)/2;
        midy=(y2+y4)/2;
        }
    if(x1==x4&&y1==y4)
        {
        x5=x1; y5=y1;
        midx=(x2+x3)/2;
        midy=(y2+y3)/2;
        }
    if(x2==x3&&y2==y3)
        {
        x5=x2; y5=y2;
        midx=(x1+x4)/2;
        midy=(y1+y4)/2;
        }
    if(x2==x4&&y2==y4)
        {
        x5=x2; y5=y2;
        midx=(x1+x3)/2;
        midy=(y1+y3)/2;
        }
    //cout<<midx<<" "<<midy<<endl;
    x6=2*midx-x5;
    y6=2*midy-y5;
    printf("%.3lf %.3lf\n",x6,y6);
    }
return 0;
}
