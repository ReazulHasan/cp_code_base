#include<stdio.h>
#include<stdlib.h>
int main()
{
char a[100];
int i,n,t=0;
while(scanf("%c",&n)==1)
	{
	char c;
	a[t++]=n;
	while((c=getchar())==' ')
		scanf("%c",&a[t++]);
	}
	printf("No. of elements is %d\n",t-1);
	for(i=0;i<t-2;i++)
		printf("%c  ",a[i]);
}