#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a;
int b=1;
while(cin>>a)
    {
    int coun=0;
    while(b>0)
    {
    b=(b * 10 +1)%a;
    //cout<<b<<endl;
    coun++;
    }
    if(a>1)
    cout<<coun+1<<endl;
    else
        cout<<1<<endl;
    b=1;
    }
return 0;
}
