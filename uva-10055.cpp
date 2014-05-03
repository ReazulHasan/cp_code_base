#include<stdio.h>
int main()
{
unsigned long int a,b,c;
while(scanf("%u %u",&a,&b)==2)
{
	if(a==b) break;
if(a>b)
	{
	c=a-b;
	printf("%u\n",c);
	}
else
	{
	c=b-a;
	printf("%u\n",c);
	}
}
return 0;
}
