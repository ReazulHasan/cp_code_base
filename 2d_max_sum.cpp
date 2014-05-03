#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
int a[100][100],b[100],i,j,k,x,y,n;
while(cin>>n)
    {
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    int max=0;
    for(i=0;i<n;i++)
        {
        int now=0;
        for(j=0;j<n;j++)
            b[j]=0;
        for(j=i;j<n;j++)
            {
            now=0;
            for(k=0;k<n;k++)
                {
                b[k]+=a[j][k];
                now+=b[k];
                if(max<now)
                    max=now;
                if(now<0)
                    now=0;
                }
            }
        }
    cout<<max<<endl;
    }
return 0;
}
