#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<set>
using namespace std;

#define maxn 1000000

int a[maxn],b[maxn];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=maxn;)
    {
    for(j=i+i;j<=maxn;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=1;
b[0]=2;
mp[2]=1;
for(i=3;i<=maxn;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
}

int main()
{
seive();
int n,i,j;
while(cin>>n&&n)
    {
    set<int> st;
    int coun=0;
    for(i=0;b[i]<n;i++)
        {
        int nw=n-b[i];
        if(mp[nw]==1)
            {
            if(b[i]==nw)
                coun++;
            else
                {
                st.insert(b[i]);
                st.insert(nw);
                }
            }
        }
    int res=st.size();
    res/=2;
    res+=coun;
    cout<<res<<endl;
    }
return 0;
}
