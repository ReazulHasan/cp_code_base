#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

double pi=2.0*acos(0.0);

int main()
{
int i,j,k,cas=0;
double a,b,c,peri,hi,lo,mid,r,theta,len,bred,s;
string s1;
while(cin>>a>>s1>>b)
    {
    cas++;
    lo=0; hi=200;
    while(1)
        {
        mid=(lo+hi)/2;
        len=a*mid; bred=b*mid;
        r=sqrt(len*len+bred*bred)/2;
        theta=atan(b/a);
        s=r*theta*2;
        if(fabs((len+s)-200.0)<=0.000001)
            break;
        if((len+s)<200.0)
            lo=mid;
        else
            hi=mid;
        }
    //cout<<"Case "<<cas<<": "<<len<<" "<<bred<<endl;
    //cout<<s1<<endl;
    s1.clear();
    printf("Case %d: %.10lf %.10lf\n",cas,len,bred);
    }
return 0;
}
