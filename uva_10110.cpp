#include<stdio.h>
#include<math.h>
int main()
{
double n;
while(scanf("%lf",&n)==1)
	{
    if(n==0) break;
	if(floor(sqrt(n))==ceil(sqrt(n)))
		printf("yes\n");
	else printf("no\n");
	}
return 0;
}
