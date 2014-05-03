#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a[100],i,j;
int max=0,now=0;
for(i=0;i<5;i++)
    cin>>a[i];
for(i=0;i<5;i++)
    {
    now=now+a[i];
    if(now>max)
        max=now;
    if(now<0)
        now=0;
    }
cout<<max<<endl;
return 0;
}
