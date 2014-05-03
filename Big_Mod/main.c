#include <stdio.h>
int main()
{
    long int i,x,b,p,m;
    scanf("%ld %ld %ld",&b,&p,&m);
    x=b%m;
    for(i=2;i<=p;i++)
    {
        x=(x%m*b%m)%m;
    }
    printf("%ld\n",x);
    return 0;
}

