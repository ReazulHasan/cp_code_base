#include<stdio.h>
# define size 100000
int main()
{
    int a[size],b[size],n,i,j,index=1;
    scanf("%d",&n);
    for(i=2;i*i<=n;i++)
        {
        for(j=2;i*j<=n;j++)
            a[i*j]=1;
        }
    b[0]=2;
    for(i=3;i<=n;i++)
        {
        if(a[i]==0)
            b[index++]=i;
        }
    for(i=0;i<index;i++)
        printf("%d\n",b[i]);
return 0;
}
