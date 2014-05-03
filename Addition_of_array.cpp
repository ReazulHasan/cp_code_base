#include<stdio.h>
#include<math.h>
int main()
{
int a[100],b[100],c[150],i,sum=0,n,m,car=0,t=0,s=0;
while(scanf("%d",&n)==1)
	{
	char c;
	a[t++]=n;
	while((c=getchar())==' ')
		{
		scanf("%d",&a[t++]);
		}
	}
while(scanf("%d",&m)==1)
	{
	char d;
	b[s++]=m;
	while((d=getchar())==' ')
		{
		scanf("%d",&b[s++]);
		}
	}
if(s==t)
	{
	for(i=s-1;i>=0;i--)
		{
		sum=a[i]+b[i]+car;
		c[i]=sum%10;
		car=floor(sum/10);
		}
	}
for(i=0;i<s;i++)
printf("%d",c[i]);
return 0;

}
