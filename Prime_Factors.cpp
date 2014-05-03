#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define max 1000000

int a[max],b[max];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=max;i++)
    for(j=i+i;j<=max;j+=i)
        a[j]=1;
int k=0;
for(i=2;i<=max;i++)
    if(a[i]==0)
        {
        mp[i]=1;
        b[k++]=i;
        }
/*for(i=0;i<k;i++)
    cout<<b[i]<<" ";*/
}

int main()
{
long long i,j;
long long n;
vector<int> v;
seive();
while(cin>>n&&n)
    {
    int flag=0;
    cout<<n<<" = ";
    if(n<0)
        {
        cout<<"-1";
        n*=-1;
        flag=1;
        }
    int flag1=0;
    for(i=0;i*i<=n;i++)
        {
        while(n%b[i]==0&&n>1)
            {
            flag1=1;
            v.push_back(b[i]);
            n/=b[i];
            if(mp[n]==1)
                {
                v.push_back(n);
                n=1;
                break;
                }
            }
        }
    if(flag1==0)
        v.push_back(n);
    for(j=0;j<v.size();j++)
        {
        if(flag==1)
            cout<<" x ";
        else if(flag==0&&j>0)
            cout<<" x ";
        cout<<v[j];
        }
    cout<<endl;
    v.clear();
    }
return 0;
}
