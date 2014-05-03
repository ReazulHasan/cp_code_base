#include<stdio.h>
int main()
{
int a[15000],n,b,i,m=0,j,k,count1=1,count2=0,item,flag=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	scanf("%d",&b);
	for(j=0;j<b;j++)
		{
		scanf("%d",&a[j]);
		m++;
		}
	for(j=0;j<m;j++)
		{
		item=a[j];
			for(k=j+1;k<m;k++)
				{
				if(a[k]==item)
					count1++;
				}
			if(j==0)
				{
				count2=count1;
				count1=1;
				}
			else
				{
				if(count1>=count2)
					count2=count1;
				count1=1;
				}
		}
	printf("%d\n",count2);
	count1=1; count2=0; m=0;
	}
return 0;
}