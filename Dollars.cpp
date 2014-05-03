#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

long long a[60000];

int main()
{
int i,j,k;
long long coin[20];
coin[0]=5; coin[1]=10; coin[2]=20; coin[3]=50; coin[4]=100; coin[5]=200;
coin[6]=500; coin[7]=1000; coin[8]=2000;
coin[9]=5000; coin[10]=10000;
a[0]=1;
for(i=0;i<11;i++)
    {
    int c=coin[i];
    for(j=0;j<40000;j++)
        a[j+c]+=a[j];
    }
double num;
int m,n;
while(scanf("%d.%d",&m,&n)==2)
    {
    if(m==0&&n==0)
        break;
    int x=m*100+n;
    num=x/100;
    //cout<<m<<" "<<n<<" "<<x<<endl;
    long long res=a[x];
    printf("%3d.",m);
    if(n<10)
        printf("0%d",n);
    else
        printf("%2d",n);
    printf("%17lld\n",res);
    //cout<<res<<endl;
    }
return 0;
}
