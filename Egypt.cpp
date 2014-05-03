#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
long long a[10],i,j,x,y,z;
while(cin>>a[0])
    {
    cin>>a[1]>>a[2];
    if(a[0]==0&&a[1]==0&&a[2]==0)
        break;
    if(a[0]<=0||a[1]<=0||a[2]<=0)
        {
        cout<<"wrong"<<endl;
        continue;
        }
    sort(a,a+3);
    x=a[0]*a[0];
    y=a[1]*a[1];
    z=a[2]*a[2];
    if((x+y)==z)
        cout<<"right"<<endl;
    else
        cout<<"wrong"<<endl;
    }
return 0;
}
