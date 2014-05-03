#include <stdio.h>

int main()
{
    int i;
    float a[12],avg,sum=0;
    for(i=0;i<12;i++)
        {
        scanf("%f",&a[i]);
        }
    for(i=0;i<12;i++)
        sum+=a[i];
    avg=sum/12;
    printf("$%.2f",avg);
    return 0;
}
