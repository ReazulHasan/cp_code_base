#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int recur(int n)
{
if(n==1) return 1;
if(n%2==0) return 2*recur(n/2)+2;
else return 2*recur(n/2);
}

int main()
{
int i,j,n;
while(cin>>n&&n)
    {
    int res=recur(n);
    cout<<res<<endl;
    }
return 0;
}
