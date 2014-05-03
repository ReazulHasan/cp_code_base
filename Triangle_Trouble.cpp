#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int n,t,i,j,k;
double a[10009],x,y,z,s,tri;
cin>>t;
while(t--)
    {
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int pos=n-1;
    int flag=0;
    double hi=0.0;
    while(pos>1)
        {
        x=a[pos];
        y=a[pos-1];
        z=a[pos-2];
        if(x<(y+z))
            {
            flag=1;
            s=(x+y+z)/2;
            tri=sqrt(s*(s-x)*(s-y)*(s-z));
            if(hi<tri)
                hi=tri;
            //printf("%.2lf\n",tri);
            //break;
            }
        pos--;
        }
    if(flag==0)
        cout<<"0.00"<<endl;
    }
return 0;
}
