#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
int i,j,k,x;
int n,a[100],b[100],res[100][100];
cin>>n;
for(i=1;i<=n;i++)
    {
    cin>>x;
    a[x]=i;
    }
//return 0;
while(cin>>x)
    {
    b[x]=1;
    for(i=2;i<=n;i++)
        {
        cin>>x;
        b[x]=i;
        }
    int m=n;
    for(i=0;i<=m;i++)
        res[0][i]=0;
    for(i=0;i<=m;i++)
        res[i][0]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            {
            if(a[i]==b[j])
                res[i][j]=res[i-1][j-1]+1;
            else if(res[i-1][j]>res[i][j-1])
                res[i][j]=res[i-1][j];
            else
                res[i][j]=res[i][j-1];
            }
    cout<<res[n][n]<<endl;
    }
return 0;
}
