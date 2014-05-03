#include<stdio.h>
#include<math.h>
#include<string.h>
#define p 1000
int main()
{
int res,car=0,i,x,y,l;
char a[p],b[p],c[p];
scanf("%s %s",&a,&b);
x=strlen(a);
y=strlen(b);
if(x>y)
	{
	strrev(b);
	for(i=y;i<x;i++)
		b[i]='0';
	strrev(b);
	}
else if(y>x)
	{
	strrev(a);
	for(i=x;i<y;i++)
		a[i]='0';
	strrev(a);
	}
l=strlen(a);
for(i=l-1;i>=0;i--)
{
	res=a[i]+b[i]-'0'-'0'+car;
	c[i+1]=res%10+'0';
	car=floor(res/10);
}
if(car==0)
	{
	for(i=0;i<x;i++)
		{
		c[i]=c[i+1];
		if(i==x-1) c[x]='\0';
		}
	printf("%s\n",c);
	}
else
	{
	c[0]=car+'0';
	c[x+1]='\0';
	printf("%s",c);
	}
return 0;
}