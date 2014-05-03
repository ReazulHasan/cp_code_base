#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

int flg[1000009],prim[1000009];

int seive()
{
int i,j,k;
for(i=2;i*i<1000000;)
    {
    for(j=i+i;j<1000000;j+=i)
        flg[j]=1;
    for(i++;flg[i];i++);
    }
prim[0]=2;
k=1;
for(i=3;i<1000000;i+=2)
    if(flg[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int main()
{
int i,j,k,n,a;
seive();
while(cin>>n&&n)
    {
    a=n;
    int mult=1;
    for(i=0;prim[i]*prim[i]<=n;i++)
        {
        if(a%prim[i]==0)
            {
            int coun=0;
            while(a%prim[i]==0)
                {
                coun++;
                a/=prim[i];
                }
            mult*=(2*coun+1);
            }
        }
    if(a>1)
        mult*=3;
    cout<<n<<" "<<mult/2+1<<endl;
    }
return 0;
}
