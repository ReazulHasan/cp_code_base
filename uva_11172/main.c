#include <stdio.h>
int main()
{
    int n,i,flag=1;
    long int a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            scanf("%ld %ld",&a,&b);
            if(a>b) printf(">\n");
            else if(a<b)
                printf("<\n");
            else
                printf("=\n");
        }
    return 0;
}
