#include <stdio.h>
#include<math.h>
#define size 1000000
    int a,b,i,j,k,n,x,sum=0,index=1,r,count=0,p,q,z,pos,item;
    int c[size+5],d[size+5],e[size+5];
int digit_prime(int s)
{
    int m=0;
    item=s;
    for(i=0;i<index;i++)
        {
            if(d[i]==item)
            {
                while(item>9)
                {
                    sum+=item%10;
                    item/=10;
                }
                sum+=item;
                for(k=0;k<=d[s];k++)
                {
                    if(d[k]==sum)
                    return 1;
                }
            return 0;
            }
        }
}
int prime()
{
    for(i=2;i*i<=size+5;i++)
        {
        for(j=2;i*j<=size+5;j++)
            c[i*j]=1;
        }
    c[0]=2;
    for(i=3;i<=size+5;i+=2)
        {
        if(c[i]==0)
            d[index++]=i;
        }
    for(i=0;i<=size+5;i++)
    {
        if(digit_prime(i))
            k++;
        e[i]=k;
    }
    return 0;
}
int main()
{
    prime();
    scanf("%d",&n);
    for(q=1;q<=n;q++)
        {
        int v;
        scanf("%d %d",&a,&b);
        v=e[b]-e[a];
        printf("%d\n",v);
        }
    return 0;
}
