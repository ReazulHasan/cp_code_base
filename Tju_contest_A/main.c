#include <stdio.h>
#include <math.h>

int main()
{
    int n,a[100],i,b,c,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b);
        for(j=0;j<b*4;j++)
            scanf("%d",&a[j]);
        k=0;
        while(k<b*4)
        {
            if(a[k]==a[k+2])
                c=a[k+1]-a[k+3];
            else
                c=a[k+2]-a[k];
            sum+=c;
            k+=4;
            c=0;
            printf("%d",k);
        }
    k=0;
    printf("%d",sum*2);
    sum=0;
    }

    return 0;
}
