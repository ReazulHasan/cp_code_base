#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

unsigned long long a[200][200];

int main()
{
int i,j,k,n;
for(i=1;i<=100;i++)
    a[1][i]=1;
for(i=1;i<=100;i++)
    a[i][1]=i;
for(i=2;i<=100;i++)
    for(j=2;j<=100;j++)
        a[i][j]=((a[i-1][j]+a[i][j-1])%1000000);
while(cin>>n>>k)
    {
    if(n==0&&k==0)
        break;
    unsigned long long res;
    res=(a[k][n]);
    cout<<res<<endl;
    }
return 0;
}
