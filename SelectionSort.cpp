#include<stdio.h>
#include<math.h>

int main()
{
    int ara[15],i,j;

    for(i=0;i<10;i++)
        scanf("%d",&ara[i]);
    for(j=0;j<10;j++){
        int min=21474835,minpos=-1;
        for(i=j;i<10;i++)
        {
            if(min>ara[i])
            {
                minpos = i;
                min = ara[i];
            }
        }
        if(minpos >= 0)
            {
                int temp = ara[minpos];
                ara[minpos] = ara[j];
                ara[j] = temp;
            }

        printf("Step%d: ",j+1);
        int k;
        for(k=0;k<10;k++)
            printf(" %d",ara[k]);
        printf("\n");
    }
    for(i=0;i<10;i++)
        printf("%d ",ara[i]);
    //printf("Hellow World!!!");
}
