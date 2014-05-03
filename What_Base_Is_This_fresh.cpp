#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char a[1000],b[1000];

int base2(int bas2)
{
int i,res=0;
for(i=0;i<strlen(b);i++)
    {
    res*=bas2;
    if(b[i]>='A'&&b[i]<='Z')
        res+=(b[i]-'0')-7;
    else
        res+=b[i]-'0';
    }
return res;
}

int base1(int bas1)
{
int i,res=0;
for(i=0;i<strlen(a);i++)
    {
    res*=bas1;
    if(a[i]>='A'&&a[i]<='Z')
        res+=(a[i]-'0')-7;
    else
        res+=a[i]-'0';
    }
return res;
}


int main()
{
int i,j;
while(cin>>a>>b)
    {
    char num1='0',num2='0';
    int bas1,bas2,res1,res2;
    for(i=0;i<strlen(a);i++)
        if(num1<=a[i])
            num1=a[i];
    if(num1>='A'&&num1<='Z')
        bas1=(num1-'0')-6;
    else
        bas1=(num1-'0')+1;
    for(i=0;i<strlen(b);i++)
        if(num2<=b[i])
            num2=b[i];
    if(num2>='A'&&num1<='Z')
        bas2=(num2-'0')-6;
    else
        bas2=(num2-'0')+1;
    if(bas1==1&&bas2==1)
        cout<<a<<" (base "<<2<<") = "<<b<<" (base "<<2<<")"<<endl;
    else{
    res1=base1(bas1);
    res2=base2(bas2);
    //cout<<res1<<" "<<res2<<endl;
    int flag=0;
    while(1)
        {
        if(res1==res2)
            {
            flag=1;
            break;
            }
        /*if(bas1==36&&bas2==36)
            {
            flag=2;
            break;
            }*/
        if(res1>res2)
            {
            if(++bas2>36)
                {
                flag=2;
                break;
                }
            res2=base2(bas2);
            }
        if(res1<res2)
            {
            if(++bas1>36)
                {
                flag=2;
                break;
                }
            res1=base1(bas1);
            }
        }
    if(flag==1)
        cout<<a<<" (base "<<bas1<<") = "<<b<<" (base "<<bas2<<")"<<endl;
    if(flag==2)
        cout<<a<<" is not equal to "<<b<<" in any base 2..36"<<endl;
    flag=0;
        }
    for(i=0;i<1000;i++)
        {
        a[i]='\0';
        b[i]='\0';
        }
    }
return 0;
}
