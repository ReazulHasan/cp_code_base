#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char a[50][50],b[50],c[50][50],d[50],e[50];

int dec1(int j)
{
int i,res=0;
for(i=0;a[j][i]!='\0';i++)
    {
    res*=16;
    if(a[j][i]>='A')
        res+=a[j][i]-'0'-7;
    else
        res+=a[j][i]-'0';
    }
return res;
}

int dec2(int j)
{
int i,res=0;
for(i=0;c[j][i]!='\0';i++)
    {
    res*=16;
    if(c[j][i]>='A')
        res+=c[j][i]-'0'-7;
    else
        res+=c[j][i]-'0';
    }
return res;
}

int main()
{
int n,i=0,j,m,x;
cin>>n;
while(n)
    {
    n--;
    cin>>a[i]>>b[i]>>c[i];
    i++;
    }
int q=0;
for(j=0;j<i;j++)
    {
    for(x=0;x<50;x++)
        {
        d[x]='\0';
        e[x]='\0';
        }
    int num;
    int num1=dec1(j);
    int num2=dec2(j);
    int s=num1,t=num2;
    int p=0;
    while(1)
        {
        d[p++]=(num1%2)+'0';
        num1/=2;
        if(num1==0)
            break;
        }
    for(m=p;m<13;m++)
        d[m]='0';
    p=0;
    while(1)
        {
        e[p++]=(num2%2)+'0';
        num2/=2;
        if(num2==0)
            break;
        }
    for(m=p;m<13;m++)
        e[m]='0';
    if(b[q]=='+')
        num=s+t;
    else if(b[q]=='-')
        num=s-t;
    q++;
    for(m=12;m>=0;m--)
        cout<<d[m];
    cout<<" "<<b[j]<<" ";
    for(m=12;m>=0;m--)
        cout<<e[m];
    cout<<" = "<<num;
    cout<<endl;
    }
return 0;
}
