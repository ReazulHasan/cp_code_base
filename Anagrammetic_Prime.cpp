#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

map<int,int> mp,check;
int flag[2000],prim[2000];
vector<int> anna;

int seive()
{
int i,j,k;
for(i=2;i*i<=1000;i++)
    for(j=i+i;j<=1000;j+=i)
        flag[j]=1;
prim[0]=2;
mp[2]=1;
k=1;
for(i=3;i<=1000;i+=2)
    if(flag[i]==0)
        {
        prim[k++]=i;
        mp[i]=1;
        }
anna.push_back(2);
anna.push_back(5);
for(i=0;i<k;i++)
    {
    vector<int> v,hoy;
    int x=prim[i],flg=0,flag=0;
    //cout<<"Prime: "<<x<<endl;
    hoy.push_back(x);
    while(x>0)
        {
        int dig=x%10;
        x/=10;
        v.push_back(dig);
        if(dig%2==0||dig==5)
            {
            flg=1;
            break;
            }
        }
    sort(v.begin(),v.end());
    if(!flg)
        {
        int len=v.size(),now=0;
        for(j=0;j<len;j++)
            {
            now*=10;
            now+=v[j];
            }
        //cout<<"len: "<<len<<endl;
        //cout<<"now1: "<<now<<endl;
        hoy.push_back(now);
        if(mp[now]==1)
            {
            while(next_permutation(v.begin(),v.end()))
                {
                now=0;
                for(j=0;j<len;j++)
                    {
                    now*=10;
                    now+=v[j];
                    }
                //cout<<"now2: "<<now<<endl;
                hoy.push_back(now);
                if(mp[now]==0)
                    {
                    flag=1;
                    break;
                    }
                }
            }
        else flag=1;
        if(!flag)
            {
            int ln=hoy.size();
            for(j=0;j<ln;j++)
                {
                if(check[hoy[j]]==0)
                    {
                    anna.push_back(hoy[j]);
                    //cout<<hoy[i]<<" ";
                    check[hoy[j]]=1;
                    }
                }
            }
        }
    }
return 0;
}

int main()
{
int i,j,k,n;
seive();
int len=anna.size();
//cout<<" total: "<<len<<endl;
sort(anna.begin(),anna.end());
while(cin>>n&&n)
    {
    if(n>=991)
        cout<<"0"<<endl;
    else
        {
        int last,fl=1;
        if(n<10)
            last=10;
        else if(n<100)
            last=100;
        else if(n>=100)
            last=1000;
        for(i=0;i<=len;i++)
            {
            if(anna[i]>n&&anna[i]<last)
                {
                fl=0;
                cout<<anna[i]<<endl;
                break;
                }
            }
        if(fl)
            cout<<"0"<<endl;
        }
    }
/*for(i=0;i<len;i++)
    cout<<anna[i]<<" ";*/
return 0;
}
