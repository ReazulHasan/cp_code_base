#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
using namespace std;

#define sz 1000000

int a[sz],b[sz],c[sz];
map<int,int> mp,mp1;
vector<int> vec;

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=2;
mp[2]=1;
int k=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
for(i=0;i<k;i++)
    if(mp1[b[i]]==0)
    {
    int it=b[i],j=1,k,flag=0,fl=0;
    int x=(log10(it)+1);
    vec.push_back(it);
    while(j<x)
        {
        fl=1;
        int y=it%10;
        if(y==0||y%2==0)
            {
            flag=1;
            break;
            }
        it/=10;
        for(k=1;k<x;k++)
            y*=10;
        it+=y;
        if(mp[it]==0)
            {
            flag=1;
            break;
            }
        vec.push_back(it);
        //cout<<it<<" ";
        j++;
        }
    if(flag==0)
        {
        int s=vec.size();
        for(int l=0;l<s;l++)
            {
            c[vec[l]]=1;
            mp1[vec[l]]=1;
            }
        }
    vec.clear();
    }
for(i=100;i<=sz;i++)
    c[i]=c[i]+c[i-1];
/*for(i=100;i<=120;i++)
    cout<<c[i]<<" ";*/
}

int main()
{
seive();
int a,b;
while(cin>>a)
    {
    if(a==-1)
        break;
    cin>>b;
    int x=c[b]-c[a-1];
    if(x==0)
        cout<<"No Circular Primes."<<endl;
    else if(x==1)
        cout<<x<<" Circular Prime."<<endl;
    else
        cout<<x<<" Circular Primes."<<endl;
    }
return 0;
}
