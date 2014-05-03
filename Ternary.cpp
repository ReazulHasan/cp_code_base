#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int main()
{
char a[100000];
int i=0,j;
long long x;
while(cin>>x)
    {
    i=0;
    if(x<0)
        break;
    while(1)
        {
        int rem=x%3;
        x/=3;
        a[i++]=rem+'0';
        if(x==0)
            break;
        }
    for(j=i-1;j>=0;j--)
        cout<<a[j];
    cout<<endl;
    }
}
