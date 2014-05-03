#include<stdio.h>
int main()
{
int n,q,i,j,a[10000],b[10000],item,flag=0,count=0;
while(scanf("%d %d",&n,&q)==2)
	{
	if(n==0&&q==0) break;
	count++;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<q;i++)
		scanf("%d",&b[i]);
	printf("CASE# %d:\n",count);
	for(i=0;i<q;i++)
		{
		item=b[i];
		for(j=0;j<n;j++)
			{
			if(a[j]==item)
                {
				printf("%d found at %d\n",item,j+2);
                break;
                }
			else
				flag++;
			}
		if(flag==n) printf("%d not found\n",item);
		flag=0;
		}
	}
return 0;
}
