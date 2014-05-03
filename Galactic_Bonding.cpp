#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
int i,j,k,cas,star,kas=0;
double x,y,d,dis,x1,y1;
cin>>cas;
while(cas--)
    {
    int coun=0;
    kas++;
    vector<double> vx,vy;
    cin>>star>>dis;
    for(i=0;i<star;i++)
        {
        cin>>x>>y;
        for(j=0;j<i;j++)
            {
            x1=vx[j];
            y1=vy[j];
            d=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
            //cout<<d<<endl;
            if((dis-d)>=0.000001)
                coun++;
            }
        vx.push_back(x);
        vy.push_back(y);
        }
    cout<<"Case "<<kas<<": "<<star-coun<<endl;
    }
return 0;
}
