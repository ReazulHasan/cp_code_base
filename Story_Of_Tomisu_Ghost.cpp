#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

int flag[100009],prim[100009];

int seive()
{
int i,j,k;
for(i=2;i*i<100000;)
    {
    for(j=i+i;j<100000;j+=i)
        flag[j]=1;
    for(i++;flag[i];i++);
    }
k=1;
prim[0]=2;
for(i=3;i<100000;i+=2)
    if(flag[i]==0)
        prim[k++]=i;
/*for(i=0;i<30;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int main()
{
seive();
int i,j,k,cas=0,kas,n,z,b;
cin>>kas;
while(kas--)
    {
    cas++;
    cin>>n>>z;
    long long bas=1;
    for(i=0;prim[i]<=n;i++)
        {
        int x=n,y=prim[i],coun=0;
        while(x)
            {
            coun+=x/y;
            x/=y;
            }
        //cout<<y<<" "<<coun<<endl;
        long long num=1;
        if(coun>=z&&coun>0)
            {
            int m=coun/z;
            for(j=0;j<m;j++)
                {
                num%=10000019;
                num*=y;
                num%=10000019;
                }
            //cout<<endl;
            }
        bas=bas%10000019;
        num=num%10000019;
        bas*=num;
        bas=bas%10000019;
        //cout<<num<<" "<<" "<<y<<" "<<bas<<endl;
        }
    if(bas==1)
        cout<<"Case "<<cas<<": -1"<<endl;
    else
        cout<<"Case "<<cas<<": "<<bas<<endl;
    }
return 0;
}
