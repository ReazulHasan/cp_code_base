#include<stdio.h>
#include<string.h>
int main()
{
int i,count1=0,l;
char a[150],b[150],c[150],d[150];
for(i=0;i<150;i++)
	{
	b[i]='\0';
	c[i]='\0';
	}
while(scanf("%s",&a)==1)
	{
	if(a[0]=='0')
		{
		if(count1==1)
			{
			printf("%s\n",b);
			break;
			}
		else
			{
			printf("%s\n",c);
			break;
			}
		}
	count1++;
	if(count1==1)
		{
		int x=strlen(a);
		for(i=0;i<x;i++)
			b[i]=a[i];
		}
	else
		{
		int x=strlen(a);
		int y=strlen(b);
		if(x>y)
			{
			strrev(b);
			for(i=y;i<x;i++)
				b[i]='0';
			strrev(b);
			}
		else
			{
			strrev(a);
			for(i=x;i<y;i++)
				a[i]='0';
			strrev(a);
			}
		l=strlen(a);
		int count2=0,res=0,car=0;
		for(i=l-1;i>=0;i--)
			{
			res=a[i]-'0'+b[i]-'0'+car;
			c[count2++]=res%10+'0';
			car=res/10;
			}
		if(car>0)
			c[count2++]=car+'0';
		strrev(c);
		for(i=0;i<strlen(c);i++)
			b[i]=c[i];
		}
	}
return 0;
}
