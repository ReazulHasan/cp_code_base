#include <stdio.h>
#include<math.h>
#define size 1000
    int a,b,i,j,k,n,x,sum=0,index=1,item,r,m=1;
    int c[size],d[size],e[size];

digit_prime()
{
    for(i=2;i*i<=size;i++)
        {
        for(j=2;i*j<=size;j++)
            c[i*j]=1;
        }
    d[0]=2;
    for(i=3;i<=size;i++)
        {
        if(c[i]==0)
            d[index++]=i;
        }
    for(i=0;i<index;i++)
        printf(" %d",d[i]);
    printf("\n");
    e[0]=2;
    for(i=1;i<index;i++)
        {
            item=d[i];
            for(k=1;k<=(log10(item)+1);k++)
            {
                x=item%10;
                item/=10;
                sum+=x;
            }
            for(k=0;k<index;k++)
            {
                if(d[k]==sum)
                {
                    e[m++]=sum;
                }
            }
        sum=0;
        }
}
int main()
{
    digit_prime();
    int count1=0,count2=m-1;
    printf("count1=%d, count2=%d, m=%d\n",count1,count2,m-1);
    for(i=0;i<m;i++)
        printf("%d ",e[i]);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        scanf("%d %d",&a,&b);
        for(j=0;e[j]<a;j++)
            count1++;
        printf("cont1 %d\n",count1);
        for(j=m-1;e[j]>b;j--)
            count2--;
        printf("count2 %d\n",count2);
            printf("%d\n",count2-count1);
            count1=0; count2=m-1;
        }
    return 0;
}
