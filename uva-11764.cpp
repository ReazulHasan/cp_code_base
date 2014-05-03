#include<stdio.h>
int main()
{
int m,n,i,j,a[100],high=0,low=0,t=0;
scanf("%d",&m);
for(i=1;i<=m;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%d",&a[j]);
		if(t==1)
			{
			if(a[j]>a[j-1])
				++high;
			else if(a[j]<a[j-1])
				++low;
			}
		t=1;
		}
	printf("Case %d: %d %d\n",i,high,low);
	high=0; low=0;t=0;
	}
return 0;
}