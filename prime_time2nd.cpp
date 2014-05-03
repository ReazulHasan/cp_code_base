#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int prime(int p)
{
int i;
for(i=2;i*i<=p;i++)
    if(p%i==0)
        return 0;
    return 1;
}

int main()
{
int x,y,c,i;
int a[10009];
for(i=0;i<10009;i++)
    a[i]=0;
for(i=0;i<=10005;i++)
    {
    int num=i*i+i+41;
    a[i]=prime(num);
    }
while(cin>>x>>y)
    {
    int coun=0;
for(i=x;i<=y;i++)
    if(a[i]==1)
        coun++;
double t=y-x+1;
double res=(double)coun/t;
double eps = 0.00001;
    res*=100;
    res+=eps;
    printf("%.2lf\n",res);
    res=0;
    }
return 0;
}
