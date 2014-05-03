#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
using namespace std;
char a[1000],b[1000];
int flag=0;
int base(int size,int min,int num)
{
int i;
while(min<=36)
    {
    min++;
    //cout<<min<<endl;
    int res=0;
    for(i=0;i<size;i++)
        {
        res*=min;
        if(ar[i]>='A'&&ar[i]<='Z')
            res+=(ar[i]-'0')-7;
        else
            res+=ar[i]-'0';
        }
    if(res==num)
        return min;
    else if(res>num||min>=36)
        return 0;
    }
}

int main()
{
int i,j;
while(cin>>a>>b)
    {
    char x='0',y='0';
    int p,q;
    int num1=0,num2=0;
    p=strlen(a); q=strlen(b);
    for(i=0;i<p;i++)
        if(x<=a[i])
            x=a[i];
    for(i=0;i<q;i++)
        if(y<=b[i])
            y=b[i];
    int min1,min2;
    if(x>='A'&&x<='Z')
        min1=(x-'0')-6;
    else
        min1=(x-'0')+1;
    //cout<<"min1 "<<min1<<endl;
    if(y>='A'&&y<='Z')
        min2=(y-'0')-6;
    else
        min2=(y-'0')+1;
    for(i=0;i<p;i++)
        {
        num1*=min1;
        if(a[i]>='A'&&a[i]<='Z')
            num1+=(a[i]-'0')-7;
        else
            num1+=a[i]-'0';
        }
    for(i=0;i<q;i++)
        {
        num2*=min2;
        if(b[i]>='A'&&b[i]<='Z')
            num2+=(b[i]-'0')-7;
        else
            num2+=b[i]-'0';
        }
    if(num1==num2&&num1&&num2)
        cout<<a<<" (base "<<min1<<") = "<<b<<" (base "<<min2<<")"<<endl;
    else if((!num1&&num2)||(num1&&!num2))
        cout<<a<<" is not equal to "<<b<<" in any base 2..36"<<endl;
    else if(!num1&&!num2)
        cout<<a<<" (base "<<2<<") = "<<b<<" (base "<<2<<")"<<endl;
    else if(num1>num2)
        {
        flag=1;
        int f=base(q,min2,num1);
        if(f==0)
            cout<<a<<" is not equal to "<<b<<" in any base 2..36"<<endl;
        else
            cout<<a<<" (base "<<min1<<") = "<<b<<" (base "<<f<<")"<<endl;
        }
    else if(num1<num2)
        {
        flag=2;
        int f=base(p,min1,num2);
        if(f==0)
            cout<<a<<" is not equal to "<<b<<" in any base 2..36"<<endl;
        else
            cout<<a<<" (base "<<f<<") = "<<b<<" (base "<<min2<<")"<<endl;
        }
    for(i=0;i<1000;i++)
        {
        a[i]='\0';
        b[i]='\0';
        }
    }
return 0;
}
