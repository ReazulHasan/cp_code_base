#include<stdio.h>
int main()
{
int a=1,b=1,c=0,i,n,p=0,q=0,x,y,res=0;
scanf("%d %d %d",&x,&y,&n);
if(n>=3)
{
for(i=3;i<=n;i++)
	{
	c=a+b;
	a=b;
	b=c;

	if(i==n-1) p=c*x;
	if(i==n-2) q=c*y;
	}
res=(p+q)%7;
printf("%d",res);
}
}