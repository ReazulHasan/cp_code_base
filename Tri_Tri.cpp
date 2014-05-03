#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

double a[30],b[30];

double cross(int x,int y,int z)
{
return (a[y]-a[x])*(b[z]-b[x])-(b[y]-b[x])*(a[z]-a[x]);
}

int main()
{
int t,i,j,k,cas=0;
double d013,d014,d015,d023,d024,d025,d123,d124,d125,d340,d341,d450,d451,d350,d351,d342,d352,d452;
cin>>t;
while(t--)
    {
    cas++;
    int flag=0;
    for(i=0;i<6;i++)
        cin>>a[i]>>b[i];
    d013=cross(0,1,3);
    d014=cross(0,1,4);
    d015=cross(0,1,5);
    d023=cross(0,2,3);
    d024=cross(0,2,4);
    d025=cross(0,2,5);
    d123=cross(1,2,3);
    d124=cross(1,2,4);
    d125=cross(1,2,5);
    d340=cross(3,4,0);
    d341=cross(3,4,1); //
    d450=cross(4,5,0);
    d451=cross(4,5,1);
    d350=cross(3,5,0);
    d351=cross(3,5,1);
    d342=cross(3,4,2);
    d342=cross(3,4,2);
    d352=cross(3,5,2);
    d452=cross(4,5,2);
    if(((d013>0&&d014<0)||(d013<0&&d014>0))&&((d340>0&&d341<0)||(d340<0&&d341>0)))
        flag=1;
    if(((d013>0&&d015<0)||(d013<0&&d015>0))&&((d350>0&&d351<0)||(d350<0&&d351>0)))
        flag=1;
    if(((d014>0&&d015<0)||(d014<0&&d015>0))&&((d450>0&&d451<0)||(d450<0&&d451>0)))
        flag=1;
    if(((d023>0&&d024<0)||(d023<0&&d024>0))&&((d340>0&&d342<0)||(d340<0&&d342>0)))
        flag=1;
    if(((d023>0&&d025<0)||(d023<0&&d025>0))&&((d350>0&&d352<0)||(d350<0&&d352>0)))
        flag=1;
    if(((d024>0&&d025<0)||(d024<0&&d025>0))&&((d450>0&&d452<0)||(d450<0&&d452>0)))
        flag=1;
    if(((d123>0&&d124<0)||(d123<0&&d124>0))&&((d341>0&&d342<0)||(d341<0&&d342>0)))
        flag=1;
    if(((d123>0&&d125<0)||(d123<0&&d125>0))&&((d351>0&&d352<0)||(d351<0&&d352>0)))
        flag=1;
    if(((d124>0&&d125<0)||(d124<0&&d125>0))&&((d451>0&&d452<0)||(d451<0&&d452>0)))
        flag=1;
    cout<<"pair "<<cas<<": ";
    if(flag)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    }
return 0;
}
