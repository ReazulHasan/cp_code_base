#include<stdio.h>
int main()
{
int m,n,i,j;
unsigned long int a,b,c,sum=0;
scanf("%d",&m);
for(i=1;i<=m;i++)
	{
	scanf("%d",&n);
	for(j=1;j<=n;j++)
		{
		scanf("%u %u %u",&a,&b,&c);
		
			sum+=a*c;
			
		}
	printf("%u\n",sum);
	sum=0;
	}
return 0;
}