#include<stdio.h>
int main()
{
int n,a,i,count=0;
while(scanf("%d",&n)==1)
	{
	if(n==0) break;
	else if(n>=3&&n<=100)
	{
	for(i=1;i<n;i++)
		{
		if(i<n-i) count++;
		}
	printf("%d\n",count);
	count=0;
	}
	}
return 0;
}