#include<stdio.h>
int main()
{
float h,m,a1,a2,a3,b1,result;
while(scanf("%f:%f",&h,&m)==2)
	{
	if(h==0&&m==0) break;
	a1=h*30;
	a2=m/2;
	a3=a1+a2;
	b1=m*6;
	if(a3>=b1)
	result=a3-b1;
	else result=b1-a3;
	if(result>180)
		printf("%.3f\n",360-result);
	else
		printf("%.3f\n",result);
	}
return 0;
}