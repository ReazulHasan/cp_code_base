#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],n,b,i,j,temp,loc,count=0;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        a[0]=-100;
        scanf("%d",&b);
        {
            for(i=1;i<=b;i++)
            {
                scanf("%d",&a[i]);
            }
            for(i=2;i<=b;i++)
            {
                temp=a[i];
                loc=i-1;
                while(temp<a[loc])
                {
                 a[loc+1]=a[loc];
                 count++;
                 loc--;
                }
                a[loc+1]=temp;
            }
        printf("Optimal train swapping takes %d swaps.\n",count);
        }
    count=0;
    }
return 0;
}
