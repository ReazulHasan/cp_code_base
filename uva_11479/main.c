#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    long int a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%ld %ld %ld",&a,&b,&c);
            if((a+b)<=c||(b+c)<=a||(c+a)<=b)
                printf("Case %d: Invalid\n",i);
            else
            {
                if(a==b&&b==c) printf("Case %d: Equilateral\n",i);
                else if(a!=b&&a!=c&&b!=c)
                    printf("Case %d: Scalene\n",i);
                else printf("Case %d: Isosceles\n",i);
            }
        }
    return 0;
}
