#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

long long sum=0,a,b;
int flg=0;

int calculate()
{
long long x,p,q,fow=0;

while(a%10!=0&&a<=b)
    {
    sum+=a%10;
    a++;
    }
if(a>b||a==b)
    {
    if(a==b)
        {
        while(a%10==0&&a!=0)
            a/=10;
        sum+=a%10;
        }
    flg=1;
    //cout<<"1st "<<sum<<endl;
    }
else
    {
    while(b%10!=0&&b>=a)
        {
        sum+=b%10;
        b--;
        }
    if(b<a||a==b)
        {
        if(a==b)
            {
            while(a%10==0&&b!=0)
                a/=10;
            sum+=a%10;
            }
        /*if(a%10==0&&b%10==0)
            sum+=a/10;*/
        flg=1;
        //cout<<"2nd "<<sum<<endl;
        }
    else
        {
        x=b-a;
        x/=10;
        x*=45;
        sum+=x;
        //cout<<"3rd "<<sum<<endl;
        }
    }
return 0;
}

int main()
{
long long i,j,k;
while(cin>>a>>b)
    {
    sum=0; flg=0;
    if(a<0&&b<0)
        break;
    while(1)
        {
        calculate();
        if(a>=10&&a%10==0)
            a/=10;
        if(b>=10&&b%10==0)
            b/=10;
        if(flg)
            {
            cout<<sum<<endl;
            break;
            }
        }
    }
return 0;
}
