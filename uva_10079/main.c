#include <stdio.h>
int main()
{
    int n;
    long long res,a;
    while(scanf("%d",&n)==1)
    {
        if(n<0)
            break;
        if(n%2==0)
        {
            a=n/2;
            res=a*(n+1);
            printf("%lld",res+1);
        }
        else
        {
            a=(n+1)/2;
            res=a*n;
            printf("%lld",res+1);
        }
    }
    return 0;
}
