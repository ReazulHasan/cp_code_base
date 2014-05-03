#include<iostream>
#include<cstdio>
using namespace std;

int calc(int i)
{
int coun=1;
while(i!=1)
    {
    if(i%2==0)
        i/=2;
    else
        i=(i*3)+1;
    coun++;
    }
return coun;
}

int main()
{
int a,b,x,y,i,j,temp;
while(cin>>a>>b)
    {
    int max=0;
    x=a; y=b;
    if(a>b)
        {
        temp=a;
        a=b;
        b=temp;
        }
    for(i=a;i<=b;i++)
        {
        int rs=calc(i);
        if(max<rs)
            max=rs;
        }
    cout<<x<<" "<<y<<" "<<max<<endl;
    }
return 0;
}
