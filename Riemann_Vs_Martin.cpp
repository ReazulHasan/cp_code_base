#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define sz 1000000
int a[sz+3],b[sz+3],mu[sz+3],martin[sz+3];

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
mu[1]=1;
martin[1]=1;
int k=0;
for(j=2;j<=sz;j++)
    {
    if(a[j]==0)
        {
        b[k++]=j;
        mu[j]=-1;
        }
    else
        {
        vector<int> v;
        int x=j;
        int n=x;
        int hi=0;
        for(i=0;b[i]*b[i]<=n;i++)
            {
            int coun=0;
            while(n%b[i]==0)
                {
                n/=b[i];
                coun++;
                }
            if(coun>0)
                v.push_back(b[i]);
            if(coun>hi)
                hi=coun;
            }
        if(n>1)
            v.push_back(n);
        if(hi>1)
            mu[x]=0;
        else
            {
            int len=v.size();
            if(len%2==0)
                mu[x]=1;
            else
                mu[x]=-1;
            }
        }
    martin[j]=mu[j]+martin[j-1];
    }
}

int main()
{
seive();
int num;
while(cin>>num&&num)
    {
    int r=mu[num];
    int s=martin[num];
    printf("%8d%8d%8d\n",num,r,s);
    //cout<<num<<" "<<r<<" "<<s<<endl;
    }
return 0;
}
