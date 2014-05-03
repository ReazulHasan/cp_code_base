#include <stdio.h>
int memo[10000];
long int bigmod(long int a, long int b, long int c)
    {
    if(b==1) return a%c;
    if(memo[b]!=-1)
        return memo[b];
        if(b%2==0) memo[b]=((bigmod(a,b/2,c)*bigmod(a,b/2,c))%c);
        else memo[b]=((bigmod(a,b-1,c)*bigmod(a,1,c))%c);
    return memo[b];
    }
int main()
{
    int i;
    long int x,r,b,p,m;
    while(scanf("%ld %ld %ld",&b,&p,&m)==3)
    {
        printf("\n");
        x=bigmod(b,p,m);
        printf("%ld\n",x);
        for(i=0;i<10000;i++)
            memo[i]=-1;
    }
    return 0;
}
