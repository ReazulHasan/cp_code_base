#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int a[1000009],n;

int main()
{
int i,j,coun1=0,coun2=0,k,p,q,r;
while(cin>>n)
    {
    for(k=0;k<=1000000;k++)
        a[k]=0;
    for(i=1;i*i<=n;i++)
        for(j=i+1;j*j<=n;j+=2)
            if((i*i+j*j)<=n)
                {
                if(i==1)
                    coun1++;
                else if((j%i)!=0)
                    coun1++;
                }
    for(i=1;i*i<=n;i++)
        for(j=i+1;j*j<=n;j++)
            if((i*i+j*j)<=n)
                {
                p=j*j-i*i;
                q=2*i*j;
                r=j*j+i*i;
                cout<<p<<" "<<q<<" "<<r<<endl;
                a[p]=1; a[q]=1; a[r]=1;
                }
        for(k=1;k<=n;k++)
            if(a[k]==0)
                coun2++;
        cout<<coun1<<" "<<coun2<<endl;
    coun1=0; coun2=0;
    }
return 0;
}
