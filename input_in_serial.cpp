#include<stdio.h>
int main()
{
	int i,n,a[50];
while(scanf("%d",&n)==1)
	{
	char c;
	int t=0;
	a[t++]=n;
	while((c=getchar())==' ') //takes input until gets enter//
		{
		scanf("%d",&a[t++]);
		}
for(i=0;i<t;i++)
printf("%d\n",a[i]);
	}
return 0;
}