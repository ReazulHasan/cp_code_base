#include<stdio.h>
int main()
{
int n,i,j,a[100],sum=0,temp=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	for(j=0;j<7;j++)
		{
		scanf("%d",&a[j]);
		}
	for(j=4;j<7;j++)
		{
		a[7]=-200;
		if(a[j+1]>a[j])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
	a[4]=(a[4]+a[5])/2;
	for(j=0;j<5;j++)
		{
		sum+=a[j];
		}
	if(sum>=90) printf("Case %d: A\n",i);
	if(sum>=80&&sum<90) printf("Case %d: B\n",i);
	if(sum>=70&&sum<80) printf("Case %d: C\n",i);
	if(sum>=60&&sum<70) printf("Case %d: D\n",i);
	if(sum<60) printf("Case %d: F\n",i);
	sum=0;
	}
return 0;
}