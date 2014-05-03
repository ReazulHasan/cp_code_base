#include<stdio.h>
#include<math.h>
int main()
{
int digit,n,i,count=0,a[100];
while(scanf("%d",&n)==1)
	{
	digit=floor(log10(n))+1;
	printf("%d\n",digit);
	for(i=digit-1;i>=0;i--)
		{
		a[i]=n%10;
		n/=10;
		}
	for(i=0;i<digit;i++)
		printf("%d ",a[i]);
	}
return 0;
}