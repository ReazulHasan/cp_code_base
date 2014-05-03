#include <stdio.h>
int main()
{
    int m,c,a[10000],b[10000],i;
    while(scanf("%d %d",&m,&c)==2)
    {
    if(m==0&&c==0) break;
    else
        {
        for(i=0;i<m*2;i++)
            {
            scanf("%d",&a[i]);
            }
        for(i=0;i<c*2;i++)
            {
        scanf("%d",&b[i]);
            }
        int low=2000;
        for(i=1;i<m*2;i+=2)
            {
            if(low>=a[i])
                low=a[i];
            }
        int high=-2000;
        for(i=1;i<c*2;i+=2)
            {
            if(high<=b[i]);
                high=b[i];
            }
        if(high>=low)
            printf("No\n");
        else
            printf("Yes\n");
        }
    }
    return 0;
}
