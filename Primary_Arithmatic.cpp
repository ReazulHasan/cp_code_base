#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
long long p,q,a,b,c;
int x,y,m;
while(cin>>p>>q)
    {
    m=0;
    int coun=0;
    if(p==0&&q==0)
        break;
    if(p>q)
        {
        a=p;
        b=q;
        }
    else
        {
        a=q;
        b=p;
        }
    while(a>=1)
        {
        x=a%10; y=b%10;
        a/=10; b/=10;
        //cout<<m<<" "<<x<<" "<<y<<endl;
        m+=x+y;
        if(m>=10)
            coun++;
        else m=0;
        if(m>10)
            m/=10;
        else if(m==10)
            m=1;
        }
    if(coun==0)
        cout<<"No carry operation."<<endl;
    if(coun==1)
        cout<<coun<<" carry operation."<<endl;
    if(coun>1)
        cout<<coun<<" carry operations."<<endl;
    }
return 0;
}
