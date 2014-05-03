#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int n,cas=0;
double a,b,c;
while(cin>>n&&n)
    {
    cas++;
    cout<<"Case "<<cas<<": ";
    double x,y;
    cin>>a>>b>>c;
    if(n==1)
        {
        x=(b-a)/c;
        y=(b*b-a*a)/(2*x);
        //cout<<'1'<<endl;
        printf("%.3lf %.3lf\n",y,x);
        }
    else if(n==2)
        {
        x=(b-a)/c;
        y=(b*b-a*a)/(2*c);
        //cout<<'2'<<endl;
        printf("%.3lf %.3lf\n",y,x);
        }
    else if(n==3)
        {
        x=(a*a)+(2*b*c);
        x=sqrt(x);
        y=(x-a)/b;
        //cout<<'3'<<endl;
        printf("%.3lf %.3lf\n",x,y);
        }
    else if(n==4)
        {
        x=(a*a)-(2*b*c);
        x=sqrt(x);
        y=(a-x)/b;
        //cout<<'4'<<endl;
        printf("%.3lf %.3lf\n",x,y);
        }
    }
return 0;
}
