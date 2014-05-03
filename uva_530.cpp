#include<stdio.h>
int fact(int n)
{
    if(n==0) return 1;
    else return n*fact(n-1);
}
int main()
{
    int a,b,n,k,c;
    while(scanf("%d %d",&n,&k)==2)
    {
        a=fact(n);
        b=fact(k);
        c=fact(n-k);
        a/=b;
        a/=c;
        printf("%d\n",a);
    }
}
