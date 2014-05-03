#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define sz 10000000
int a[sz+3],prim[sz+3];
int ax,by;
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=1;
prim[0]=2;
mp[2]=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        {
        prim[k++]=i;
        mp[i]=1;
        }
/*for(i=0;i<20;i++)
    cout<<prim[i]<<" ";*/
return 0;
}

int find_prim(int n)
{
int i,j,k;
for(i=0;prim[i]<n;i++)
    {
    int x=n-prim[i];
    if(mp[x]==1)
        {
        ax=prim[i];
        by=x;
        //cout<<ax<<" "<<by<<endl;
        break;
        }
    }
return 0;
}

int main()
{
seive();
int n,i,j,c,d;
while(cin>>n)
    {
    if(n%2==0)
        {
        c=2; d=2;
        n-=4;
        }
    else
        {
        c=2;
        d=3;
        n-=5;
        }
    if(n<4)
        cout<<"Impossible."<<endl;
    else
        {
        find_prim(n);
        cout<<c<<" "<<d<<" "<<ax<<" "<<by<<endl;
        }
    }
return 0;
}
