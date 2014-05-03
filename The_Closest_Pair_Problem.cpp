#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

double a[10009],b[10009];

int main()
{
int n,i,j,k;
while(cin>>n&&n)
    {
    double x1,y1,x2,y2,dis,min=987987987;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(i=0;i<n;i++)
        {
        x1=a[i]; y1=b[i];
        for(j=i+1;j<n;j++)
            {
            x2=a[j]; y2=b[j];
            dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            if(dis<min)
                min=dis;
            }
        }
    if(sqrt(min)>10000||n==0)
        cout<<"INFINITY"<<endl;
    else
        printf("%.4lf\n",sqrt(min));
    }
return 0;
}
