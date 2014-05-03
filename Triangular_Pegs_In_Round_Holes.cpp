#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
double a[1000],b[10],x,y,z,s,area,r,pi=2.0*acos(0.0);
char c;
int n,i,j,m;
cin>>n;
for(i=0;i<n;i++)
    cin>>a[i];
cin>>m;
c='A';
for(i=0;i<m;i++)
    {
    int flag=1;
    cin>>b[0]>>b[1]>>b[2];
    sort(b,b+3);
    x=b[0]; y=b[1]; z=b[2];
    double theta=acos((x*x+y*y-z*z)/(2*x*y))*(180/pi);
    //cout<<theta<<endl;
    s=(x+y+z)/2;
    area=sqrt(s*(s-x)*(s-y)*(s-z));
    r=(x*y*z)/(4*area);
    //cout<<r<<endl;
    for(j=0;j<n;j++)
        {
        if(theta>90.0)
            {
            if(z<=a[j])
                {
                if(flag)
                    cout<<"Peg "<<c<<" will fit into hole(s):";
                cout<<" "<<j+1;
                flag=0;
                }
            }
        else if(r<=(a[j]/2))
            {
            if(flag)
                cout<<"Peg "<<c<<" will fit into hole(s):";
            cout<<" "<<j+1;
            flag=0;
            }
        }
    if(flag)
        cout<<"Peg "<<c<<" will not fit into any holes";
    cout<<endl;
    c++;
    }
return 0;
}
