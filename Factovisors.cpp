#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int flag[1000009];
long long prim[1000009];

int seive()
{
int i,j,k;
for(i=2;i*i<=1000000;i++)
    for(j=i+i;j<=1000000;j+=i)
        flag[j]=1;
prim[0]=2;
k=1;
for(i=3;i<=1000000;i+=2)
    if(flag[i]==0)
        prim[k++]=i;
/*for(i=0;i<20;i++)
    cout<<prim[i]<<endl;*/
return 0;
}

int main()
{
int i,j,k;
long long a,b,x,y,m;
seive();
while(cin>>a>>b)
    {
    //cout<<a<<" "<<b<<endl;
    if(b==1)
        {
        cout<<b<<" divides "<<a<<"!"<<endl;
        continue;
        }
    vector<long long> v;
    map<long long,int> mp;
    x=b,y=a;
    //cout<<x<<endl;
    long long mult=prim[0]*prim[0];
    for(m=0;mult<=x;m++)
        {
        //cout<<mult<<endl;
        mult=prim[m+1]*prim[m+1];
        if(x%prim[m]==0)
            {
            int coun=0;
            while(x%prim[m]==0)
                {
                coun++;
                x/=prim[m];
                }
            mp[prim[m]]=coun;
            //cout<<prim[m]<<" "<<coun<<endl;
            v.push_back(prim[m]);
            }
        //cout<<prim[i]<<endl;
        }
    if(x>1)
        {
        mp[x]=1;
        v.push_back(x);
        //cout<<"hi "<<x<<endl;
        }
    int len=v.size(),fl=0;
    //cout<<len<<endl;
    for(i=0;i<len;i++)
        {
        y=a;
        int it=v[i],tot=0;
        while(y>0)
            {
            tot+=y/it;
            y/=it;
            }
        //cout<<it<<" tot "<<tot<<" ,mp[it] "<<mp[it]<<endl;
        if(mp[it]>tot)
            {
            fl=1;
            break;
            }
        }
    if(!fl)
        cout<<b<<" divides "<<a<<"!"<<endl;
    else
        cout<<b<<" does not divide "<<a<<"!"<<endl;
    }
return 0;
}
