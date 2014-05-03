#include<stdio.h>
#include<math.h>
int main()
{
    char a[10000];
    int multiple,sum=0,res=0,base=2;
    int i,digit=0,n,count=0;
    while(scanf("%d",&n)==1)
    {
        char c; int t=0;
        a[t++]=n;
        while((c=getchar())==' ')
            {
                scanf("%d",&a[t++]);
            }
            for(i=0;i<t;i++)
            printf("%d\n",a[i]);
        if(a[0]==0) break;
        digit=t;
        for(i=digit-1;i>=0;i--)
            {
            count++;
            multiple=pow(base,count)-1;
            sum+=(a[i]*multiple);
            }
            printf("%d\n",sum);
            sum=0; multiple=0; res=0; count=0;
    }
    return 0;
}
