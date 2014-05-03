#include <stdio.h>
#include <math.h>
int main()
{
    int a,x,i,y,r,b,p,m;
    scanf("%d %d %d",&b,&p,&m);
    x=b%m;
    for(i=2;i<=p;i++)
    {
        x=(x%m*b%m)%m;
    }
    printf("%d",x);
    return 0;
}
