#include<iostream>
#include<cstdio>
using namespace std;

int f91(int n)
{
if(n<=100)
    return f91(f91(n+11));
else if(n>=101)
    return n-10;
}

int main()
{
int i,j,n;
while(cin>>n&&n)
    {
    int x=f91(n);
    cout<<x<<endl;
    }
return 0;
}
