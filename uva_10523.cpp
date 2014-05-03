#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
long long sum=0,mult=1;
int a,n,i,j;
while(cin>>n>>a)
    {
    for(i=1;i<=n;i++)
        {
        j=i;
        while(j>=1)
            {
            mult*=a;
            j--;
            }
        sum+=i*mult;
        mult=1;
        }
    cout<<sum<<endl;
    sum=0; mult=1;
    }
}
