#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
double dig;
int w,l,r1,r2,sumr;
while(cin>>w>>l>>r1>>r2)
    {
    if(w==0&&l==0&&r1==0&&r2==0)
        break;
    sumr=r1*2+r2*2;
    dig=sqrt(w*w+l*l);
    if(sumr<=w)
        cout<<"S"<<endl;
    else if(sumr<=l)
        cout<<"S"<<endl;
    else if(sumr<=dig)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    }
return 0;
}
