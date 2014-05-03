#include<stdio.h>
int main()
{
int n,i,a[100],sum=0,q,result=0,moves=0,count=0,fresult=0,flag=0;
while(scanf("%d",&n)==1)
	{
	if(n==0)
		break;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		sum+=a[i];
		}
	q=sum/n;
	for(i=0;i<n;i++)
		{
		if(q<a[i])
			{
			result=a[i]-q;
			fresult+=result;
			}
		}
	printf("Set #%d\nThe minimum number of moves is %d\n\n",++count,fresult);
	}
return 0;
}
