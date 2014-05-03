#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
map<char,int> mpchar,mpflag;
map<int,int> mppr;
vector<char> v;
#define sz 10000
int a[sz+3],b[sz+3];

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
mppr[2]=1;
for(i=3;i<=sz;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mppr[i]=1;
        }
/*for(i=0;i<20;i++)
    cout<<b[i]<<" ";*/
return 0;
}

int main()
{
seive();
int t,i,j,k,m;
char c[3000],d[10];
cin>>t;
gets(d);
for(m=1;m<=t;m++)
    {
    gets(c);
    //puts(c);
    int len=strlen(c);
    //cout<<len<<endl;
    for(i=0;i<len;i++)
        mpchar[c[i]]++;
    for(i=0;i<len;i++)
        {
        char ch=c[i];
        int it=mpchar[ch];
        //cout<<ch<<" "<<it<<endl;
        if(mppr[it]==1)
            if(mpflag[ch]==0)
                {
                v.push_back(ch);
                mpflag[ch]=1;
                }
        }
    cout<<"Case "<<m<<": ";
    if(v.empty())
        cout<<"empty"<<endl;
    else
    {
    sort(v.begin(),v.end());
    int l=v.size();
    for(i=0;i<l;i++)
        cout<<v[i];
    cout<<endl;
    }
    v.clear(); mpchar.clear(); mpflag.clear();
    }
return 0;
}
