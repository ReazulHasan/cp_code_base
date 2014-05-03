#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

#define size 5005

char a[size][size];

int fibo()
{
int i,j;
for(i=0;i<size;i++)
    for(j=0;j<size;j++)
        a[i][j]='0';
a[0][size-1]='1';
a[1][size-1]='1';
int car=0;
for(i=2;i<size;i++)
    for(j=size-1;j>=0;j--)
        {
        int x=(a[i-1][j]-'0')+(a[i-2][j]-'0')+car;
        if(x>9)
            {
            a[i][j]=(x%10)+'0';
            car=x/10;
            }
        else
            {
            a[i][j]=x+'0';
            car=0;
            }
        }
/*for(i=0;i<size;i++)
    {
    for(j=0;j<size;j++)
        cout<<a[i][j];
    cout<<endl;
    }*/
return 0;
}

int main()
{
fibo();
//return 0;
int n,i;
while(scanf("%d",&n)==1)
    {
    int flag=0,k=0;
    //printf("The Fibonacci number for %d is ",n);
    while(a[n-1][k]=='0')
        k++;
    for(i=k;i<size;i++)
         printf("%c",a[n-1][i]);
    printf("\n");
    }
return 0;
}
