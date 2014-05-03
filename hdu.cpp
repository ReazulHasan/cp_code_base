#include<stdio.h>
#include<math.h>
int main()
{
int n,i;
while(scanf("%d",&n)==1)
{
	double res=0.0,ans=0.0;
	if(n<0) break;
	else{
for(i=1;i<=n;i++)
	{
	ans+=log10(i);
	
	}
res=ans+1.0;
res=floor(res);
printf("%.0lf",res);
}
}
}