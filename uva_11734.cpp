#include<stdio.h>
#include<string.h>
int main()
{
int i,n,x,y,m=0,p=0,r,s,c,d;
char t[20],j[20],a[20],b[20],q[100];
scanf("%d",&n);
gets(q);
for(i=1;i<=n;i++)
	{
	gets(t);
	gets(j);
	c=strlen(t);
	d=strlen(j);
	x=strcmp(t,j);
	for(r=0;r<20;r++)
		{
		a[r]='\0';
		b[r]='\0';
		}
	if(x==0)
		printf("Case %d: Yes\n",i);
	else
		{
		for(r=0;r<c;r++)
			{
				if(t[r]!=' ')
					{
					
					a[m]=t[r];
					m++;
					}
				
				
			}
		m=0;
		for(s=0;s<d;s++)
			{
				if(j[s]!=' ')
					{
					b[p]=j[s];
					p++;
					}

			}
		p=0;
		y=strcmp(a,b);
		if(y==0)
			printf("Case %d: Output Format Error\n",i);
		else
			printf("Case %d: Wrong Answer\n",i);
		for(s=0;s<c;s++)
			a[s]='\0';
		for(s=0;s<d;s++)
			b[s]='\0';
		}
	}
return 0;
}