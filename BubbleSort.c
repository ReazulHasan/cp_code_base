#include<stdio.h>

int main()
{
    int ara[15],i,j,last=9;
    for(i=0;i<10;i++)
        scanf("%d",&ara[i]);
    for(i=0;i<10;i++)
    {
        for(j=0;j<last;j++)
            if(ara[j]>ara[j+1])
            {
                int temp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=temp;
            }
        last--;
        printf("Step%d: ",i+1);
        for(j=0;j<10;j++)
            printf(" %d",ara[j]);
        printf("\n");
    }
    for(i=0;i<10;i++)
        printf("%d ",ara[i]);
}
