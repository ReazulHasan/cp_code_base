                        //Bismillah
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int gcd(int a,int b)
{
int c;
if(b==0)
    return a;
c=a%b;
return gcd(b,c);
}

int main()
{
char c[10],b[200];
int n,a[100],t,i,j=1,k=0,m=0,mod,max=0,item,p;
cin>>t;
gets(c);
for(i=0;i<t;i++)
    {
    gets(b);
    for(m=0;b[m]!='\0';)
        {
        int r=0,flag=0;
        while((b[m]-'0')<=9&&(b[m]-'0')>=0&&b[m]!='\0')
            {
            r*=10;
            r+=b[m]-'0';
            m++;
            flag=1;
            }
        if(flag==1)
            a[k++]=r;
        flag=0;
        m++;
        }
    for(m=0;m<200;m++)
        b[m]='\0';
    for(m=0;m<k;m++)
        for(j=m+1;j<k;j++)
            {
            item=gcd(a[m],a[j]);
            if(max<item)
                max=item;
            }
        cout<<max<<endl;
    for(j=0;j<100;j++)
        a[j]=0;
    j=0; m=0; max=0; k=0;
    }
return 0;
}
