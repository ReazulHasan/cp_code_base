#include<stdio.h>
int main()
{
int a,b,c,i,n;
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	scanf("%d %d %d",&a,&b,&c);
	if((a>b&&b>c)||(b<c&&b>a))
		printf("Case %d: %d\n",i,b);
	if((b>a&&a>c)||(a>b&&a<c))
		printf("Case %d: %d\n",i,a);
	if((a>c&&c>b)||(c>a&&c<b))
		printf("Case %d: %d\n",i,c);
	}
return 0;
}