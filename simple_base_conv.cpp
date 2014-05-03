#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

char ch(int x)
{
if(x==10)
    return 'A';
if(x==11)
    return 'B';
if(x==12)
    return 'C';
if(x==13)
    return 'D';
if(x==14)
    return 'E';
if(x==15)
    return 'F';
}

int value(char c)
{
if(c=='A')
    return 10;
if(c=='B')
    return 11;
if(c=='C')
    return 12;
if(c=='D')
    return 13;
if(c=='E')
    return 14;
if(c=='F')
    return 15;
}

int main()
{
char a[100],b[100];
int i,j;
while(cin>>a)
    {
    int m=0;
    long long num=0,res=0;
    if(a[0]=='-')
        break;
    if(a[0]=='0')
        {
        int k=0;
        i=strlen(a)-1;
        while(i>1)
            {
            if(a[i]>='A')
                num=value(a[i]);
            else
                num=a[i]-'0';
            //cout<<num<<endl;
            for(j=1;j<=k;j++)
                num*=16;
            k++;
            res+=num;
            i--;
            }
        cout<<res<<endl;
        }
    else
        {
        i=0;
        while(a[i]!='\0')
            {
            num*=10;
            num+=a[i]-'0';
            i++;
            }
        while(num>=1)
            {
            int p=num%16;
            //cout<<p<<endl;
            if(p>=10)
                b[m]=ch(p);
            else
                b[m]=p+'0';
            //cout<<b[m]<<endl;
            m++;
            num/=16;
            }
        b[m++]='x'; b[m++]='0';
        for(i=m-1;i>=0;i--)
            cout<<b[i];
        cout<<endl;
        m=0;
        }
    //cout<<num<<endl;
    for(i=0;i<100;i++)
        {
        a[i]='\0';
        b[i]='\0';
        }
    }
return 0;
}
