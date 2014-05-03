#include<stdio.h>
#include<math.h>

int main()
{
    int ara[15],i,j;
    for(i=0;i<10;i++)
        scanf("%d",&ara[i]);
    for(i=0;i<10;i++){
        int x = i,item=ara[i],itempos=i;
        while(x>0)
        {
            x--;
            if(ara[x]>item)
                {
                    int temp = ara[x];
                    ara[x] = item;
                    ara[itempos] = temp;
                    itempos = x;
                }
        }
        int k;
        printf("Step%d: ",i+1);
        for(k=0;k<10;k++)
            printf(" %d",ara[k]);
        printf("\n");
    }
    for(i=0;i<10;i++)
        printf("%d ",ara[i]);
    return 0;
}
