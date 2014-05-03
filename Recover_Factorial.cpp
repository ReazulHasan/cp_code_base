#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

#define sz 2800000

int a[sz+3],b[sz+3],res[sz+3];
map<int,int> mp;
vector<long long> v;

int seive()
{
int i,j;
for(i=2;i*i<=sz;)
    {
    for(j=i+i;j<=sz;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
int k=0;
v.push_back(0);
v.push_back(0);
for(i=2;i<=sz;i++)
    {
    if(a[i]==0)
        {
        b[k++]=i;
        v.push_back(v[i-1]+1);
        }
    else
        {
        int it=i,coun=0;
        for(j=0;b[j]*b[j]<=it;j++)
            {
            while(it%b[j]==0)
                {
                coun++;
                it/=b[j];
                }
            }
        if(it>1)
            coun++;
        v.push_back(v[i-1]+coun);
        //res[i]=res[i-1]+coun;
        }
    }
/*for(i=0;i<150;i++)
    cout<<i<<":"<<v[i]<<" ";*/
return 0;
}

int main()
{
seive();
//return 0;
int n,coun=0;
vector<long long>::iterator it;
while(cin>>n)
    {
    coun++;
    if(n<0)
        break;
    cout<<"Case "<<coun<<": ";
    it=lower_bound(v.begin(),v.end(),n);
    int x=it-v.begin();
    //cout<<v[x]<<" "<<x<<endl;
    if(v[x]!=n)
        cout<<"Not possible."<<endl;
    else
        cout<<x<<"!"<<endl;
    }
return 0;
}
