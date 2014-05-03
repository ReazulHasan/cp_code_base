#include<stdio.h>
int main()
{
int i,count=0;
char a[100];
gets(a);
for(i=0;a[i]!='\0';i++)
	{
	if(a[i]==' '&&(((a[i-1]>='a'&&a[i-1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'))||((a[i-2]>='a'&&a[i-2]<='z')||(a[i-2]>='A'&&a[i-2]<='Z'))))
		{
				++count;
		}
	}
if(((a[i-1]>='a'&&a[i-1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'))||((a[i-2]>='a'&&a[i-2]<='z')||(a[i-2]>='A'&&a[i-2]<='Z')))
	printf("%d\n",count+1);
else
	printf("%d\n",count);
return 0;
}