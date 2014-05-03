#include<stdio.h>
int main()
{
int count=0,i=0,flag=0;
char str[100];
gets(str);
while(str[i]!='\0')
	{
	if(str[i]==' ')
	{
		if(flag==1)
		{
		if((str[i-1]<='a'&&str[i-1]>='z')||(str[i-1]<='A'&&str[i-1]>='Z'))
			{
			count++;
			
			}
		}
		flag=1;
	}
	i++;
	}
printf("%d",count+1);
return 0;
}