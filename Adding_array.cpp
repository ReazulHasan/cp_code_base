#include<stdio.h>
#include<math.h>
int main()
{
char a[1000000000000000000000000000000000000000000000000000],b[100000000000000000000000000000000000000000000000000000000],c[1000000000000000000000000000000000000000000000000000000000000];
int i,sum=0,car=0;
for(i=0;i<5;i++)
	scanf("%d",&a[i]);
for(i=0;i<5;i++)
	scanf("%d",&b[i]);
for(i=4;i>=0;i--)
	{
	sum=a[i]+b[i]+car;
	c[i+1]=sum%10;
	car=floor(sum/10);
	}
	c[0]=car;
for(i=0;i<6;i++)
	printf("%d ",c[i]);
return 0;
}
