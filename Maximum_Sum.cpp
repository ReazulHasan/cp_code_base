#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int a[109][109],b[109],i,j,k,n;
while(cin>>n)
{
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        cin>>a[i][j];
int max=0;
for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
        b[j]=0;
    for(j=i;j<n;j++)
        {
        int now=0;
        for(k=0;k<n;k++)
            {
            b[k]+=a[j][k];
            now+=b[k];
            if(now>max)
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
