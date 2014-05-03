#include<stdio.h>
int main()
{
int i,n,count=0,flag=0;
while(scanf("%d",&n)==1)
{
	if(n<0) break;
else
{
flag++;
for(i=1;i<n;i+=i)
	{
	count++;
	}
printf("Case %d: %d\n",flag,count);
count=0;
}
}
return 0;
}