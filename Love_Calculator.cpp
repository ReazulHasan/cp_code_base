#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
char a[100],b[100];
int i,j,k;
while(gets(a))
    {
    int sum1=0,sum2=0;
    gets(b);
    int len1=strlen(a);
    int len2=strlen(b);
    for(i=0;i<len1;i++)
        if((a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'))
            {
            if(a[i]>='a'&&a[i]<='z')
                sum1+=(a[i]-'a'+1);
            else if(a[i]>='A'&&a[i]<='Z')
                sum1+=(a[i]-'A'+1);
            }
    for(i=0;i<len2;i++)
        if((b[i]>='a'&&b[i]<='z'||b[i]>='A'&&b[i]<='Z'))
            {
            if(b[i]>='a'&&b[i]<='z')
                sum2+=(b[i]-'a'+1);
            else if(b[i]>='A'&&b[i]<='Z')
                sum2+=(b[i]-'A'+1);
            }
        if(sum1%9==0)
            sum1=9;
        else
            sum1=(sum1%9);
        if(sum2%9==0)
            sum2=9;
        else
            sum2=(sum2%9);
        if(sum1<sum2)
            {
            int temp=sum1;
            sum1=sum2;
            sum2=temp;
            }
        double x=(double) sum1;
        double y=(double) sum2;
        double res=(y/x)*100;
        printf("%.2lf ",res);
        cout<<"%"<<endl;
    for(i=0;i<100;i++)
        {
        a[i]='\0';
        b[i]='\0';
        }
    }
return 0;
}
