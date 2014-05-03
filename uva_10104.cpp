#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,c,x,i,j;
    cin>>a>>b;
    x=gcd(a,b);
    for(i=-100;i<=100;i++)
            for(j=-100;j<=100;j++)
                if((a*i+b*j)==x)
                {
                    cout<<i<<" "<<j<<" "<<x<<endl;
                    break;
                }
return 0;
}
