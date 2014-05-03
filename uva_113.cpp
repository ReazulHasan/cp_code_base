#include<stdio.h>
int main()
{
unsigned long long n,p,mult=1;
int i,count=0,fact;
while(scanf("%u %u",&n,&p)==2)
	{
	while((p%n)==0&&p>0)
		{
		count++;
		p/=n;
		}
	fact=count/n;
	for(i=1;i<=fact;i++)
		mult*=n;
	printf("%u\n",mult);
	count=0; mult=1;
	}
return 0;
}
