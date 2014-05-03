#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int GCD(int a,int b)
{
if(b==0)
    return a;
return GCD(b,a%b);
}

int main()
{
int i,j,k,n;
while(cin>>n&&n)
    {
    int res=0;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            {
            int x=GCD(j,i);
            res+=x;
            }
    cout<<res<<endl;
    }
return 0;
}
