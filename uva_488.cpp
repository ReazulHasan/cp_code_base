#include<stdio.h>
int main()
{
int n,i,j,k,l,a,f;
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	scanf("%d",&a);
	scanf("%d",&f);
	if(i>1)
	printf("\n");
	for(j=1;j<=f;j++)
		{
		for(k=1;k<=a;k++)
			{
			for(l=1;l<=k;l++)
				printf("%d",k);
				printf("\n");
			}
		for(k=a-1;k>=1;k--)
			{
			for(l=1;l<=k;l++)
				printf("%d",k);
				printf("\n");
			}
		if(j==f) continue;
		else
		printf("\n");
		}
	if(i==n) break;
	else
	printf("\n");
	}
return 0;
}