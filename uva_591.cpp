#include<stdio.h>
int main()
{
int n,i,b,a[50],sum=0,q,result=0,moves=0,count=0,fresult=0,flag=0;
label:
while(scanf("%d",&n)==1)
	{
	if(n==0)
		break;
	else
	{
	while(scanf("%d",&b)==1)
		{
		char c;
		int t=0;
		a[t++]=b;
		while((c=getchar())==' '&&flag<n)
			{
			scanf("%d",&a[t++]);
			flag++;
			}
		
	for(i=0;i<n;i++)
		{
		sum+=a[i];
		}
	q=sum/n;
	for(i=0;i<n;i++)
	{
	if(q>a[i])
		result=q-a[i];
	else if(q<a[i])
		result=a[i]-q;
	else if(q==a[i])
		continue;
	fresult+=result;
	}
	moves=fresult/2;
	count++;
	printf("Set #%d\n",count);
	printf("The minimum number of moves is %d.\n",moves);
	printf("\n");
	moves=0; result=0; sum=0; fresult=0; flag=0;
	goto label;
		}
	}
	}
return 0;
}