#include<stdio.h>
int main()
{
int k,flag=0,m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,n,i,b=1,u=10,s=100,p=1000,f=10000,t=100000,m=1000000;
char array[500];
scanf("%d",&n);
for(i=1;i<=n;i++)
	{
	gets(array);

		for(k=0;array[k]!='\0';k++)
			{
			if(array[k]=='b'&&array[k+1]=='u'||array[k]=='u'&&array[k+1]=='s'||array[k]=='s'&&array[k+1]=='p'||array[k]=='p'&&array[k+1]=='f'||array[k]=='f'&&array[k+1]=='t'||array[k]=='t'&&array[k+1]=='m'||array[k]=='b'&&array[k+1]=='s'||array[k]=='b'&&array[k+1]=='p'||array[k]=='b'&&array[k+1]=='f'||array[k]=='b'&&array[k+1]=='t'||array[k]=='b'&&array[k+1]=='m'||array[k]=='u'&&array[k+1]=='p'||array[k]=='u'&&array[k+1]=='f'||array[k]=='u'&&array[k+1]=='t'||array[k]=='u'&&array[k+1]=='m'||array[k]=='s'&&array[k+1]=='f'||array[k]=='s'&&array[k+1]=='t'||array[k]=='s'&&array[k+1]=='m'||array[k]=='p'&&array[k+1]=='t'||array[k]=='p'&&array[k+1]=='m'||array[k]=='f'&&array[k+1]=='m')
			{
				printf("error");
				continue;
			}
	
		if(array[k]=='m')
			m1++;
		if(array[k]=='t')
			m2++;
		if(array[k]=='f')
			m3++;
		if(array[k]=='p')
			m4++;
		if(array[k]=='s')
			m5++;
		if(array[k]=='u')
			m6++;
		if(array[k]=='b')
			m7++;


		}
	if(m1<=9&&m2<=9&&m3<=9&&m4<=9&&m5<=9&&m6<=9&&m7<=9)
		{
		int result=0;
		result=m1*m+m2*t+m3*f+m4*p+m5*s+m6*u+m7*b;
		printf("%d\n",result);
		result=0; m1=0; m2=0; m3=0; m4=0; m5=0; m6=0; m7=0;
		}
	else
		{
		printf("error\n");
		m1=0; m2=0; m3=0; m4=0; m5=0; m6=0; m7=0;
		}
	}

return 0;
}