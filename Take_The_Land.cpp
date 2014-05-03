#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
int m,n,i,j,k,a[100][100],b[100];
while(cin>>m>>n&&m&&n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            {
            if(a[i][j]==0)
                a[i][j]=1;
            else
                a[i][j]=-10000;
            }
    int max=0;
    for(i=0;i<m;i++)
        {
        for(j=0;j<n;j++)
            b[j]=0;
        for(j=i;j<m;j++)
            {
            int nw=0;
            for(k=0;k<n;k++)
                {
                b[k]+=a[j][k];
                nw+=b[k];
                if(max<nw)
                    max=nw;
                if(nw<0)
                    nw=0;
                }
            }
        }
    cout<<max<<endl;
    }
return 0;
}
