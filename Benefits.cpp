#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define sz 100000
int a[sz],b[sz];

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
b[0]=2;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        b[k++]=i;
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
}

int main()
{
seive();
int t,i,j,n,lcm;
cin>>t;
while(t--)
    {
    vector<int> v;
    map<int,int> mpn,mplcm;
    cin>>n>>lcm;
    if(n>lcm)
        cout<<"NO SOLUTION"<<endl;
    else if(n==1)
        cout<<lcm<<endl;
    else if(lcm%n!=0)
        cout<<"NO SOLUTION"<<endl;
    else
    {
    for(i=0;b[i]*b[i]<=n;i++)
        {
        int coun=0;
        while(n%b[i]==0)
            {
            n/=b[i];
            coun++;
            }
        if(coun>0)
            mpn[b[i]]=coun;
        }
    if(n>1)
        mpn[n]=1;
    for(i=0;b[i]*b[i]<=lcm;i++)
        {
        int coun=0;
        while(lcm%b[i]==0)
            {
            lcm/=b[i];
            coun++;
            }
        if(coun>0)
            {
            v.push_back(b[i]);
            mplcm[b[i]]=coun;
            }
        }
    if(lcm>1)
        {
        v.push_back(lcm);
        mplcm[lcm]=1;
        }
    int len=v.size();
    //cout<<len<<endl;
    int mult=1,flag=0;
    for(i=0;i<len;i++)
        {
        int div=v[i];
        if(mplcm[div]!=0&&mpn[div]!=0)
            flag=1;
        if(mplcm[div]>mpn[div])
            {
            int x=mplcm[div];
            while(x--)
                mult*=div;
            }
        }
    if(flag==0)
        cout<<"NO SOLUTION"<<endl;
    else
        cout<<mult<<endl;
    }
    }
return 0;
}
