#include<stdio.h>
#include<string.h>
int main()
{
int i,count1=0,l;
char a[150],b[150],c[150],d[150];
for(i=0;i<150;i++)
	{
    a[i]='\0';
	b[i]='\0';
	c[i]='\0';
	d[i]='\0';
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
			printf("%s\n",d);
			break;
			}
		}
	count1++;
	if(count1==1)
		{
        int x=0;
        for(i=0;a[i]!='\0';i++)
            x++;
		for(i=0;i<x;i++)
			b[i]=a[i];
		}
	else
		{
        int x=0,y=0;
        for(i=0;a[i]!='\0';i++)
            x++;
        for(i=0;b[i]!='\0';i++)
            y++;
		if(x>y)
			{
			int index=0;
			for(i=y-1;i>=0;i--)
				d[index++]=b[i];
			for(i=y;i<x;i++)
				d[i]='0';
			index=0;
			for(i=x-1;i>=0;i--)
				b[index++]=d[i];
			}
		else
			{
			int index=0;
			for(i=x-1;i>=0;i--)
				d[index++]=a[i];
			for(i=x;i<y;i++)
				d[i]='0';
			index=0;
			for(i=y-1;i>=0;i--)
				a[index++]=d[i];
			}
        int l=0;
        for(i=0;b[i]!='\0';i++)
            l++;
		int count2=0,res=0,car=0;
		for(i=l-1;i>=0;i--)
			{
			res=a[i]-'0'+b[i]-'0'+car;
			c[count2++]=res%10+'0';
			car=res/10;
			}
		if(car>0)
			c[count2++]=car+'0';
		int z=0;
		for(i=0;c[i]!='\0';i++)
            z++;
		int index=0;
		for(i=z-1;i>=0;i--)
			d[index++]=c[i];
		for(i=0;i<z;i++)
            {
			b[i]=d[i];
			a[i]='\0';
            }
		}
	}
return 0;
}
