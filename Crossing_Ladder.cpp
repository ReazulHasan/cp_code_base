#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
double p,q,x,y,h;
while(cin>>x>>y>>h)
    {
    double hi,lo,mid,now;
    hi=min(x,y);
    p=max(x,y);
    q=min(x,y);
    cout<<p<<" "<<q<<endl;
    lo=0;
    now=p;
    while(1)
        {
        mid=(hi+lo)/2;
        now=(p/q)*mid;
        if(fabs(mid-h)<=0.000000001)
            break;
        if(mid>h)
            hi=mid;
        else
            lo=mid;
        }
    cout<<now<<endl;
    }
return 0;
}
