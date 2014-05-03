#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

#define size 10000

int a[size],b[size];
map<int,int> mp;

int seive()
{
int i,j;
for(i=2;i*i<=size;)
    {
    for(j=i+i;j<=size;j+=i)
        a[j]=1;
    for(i++;a[i];i++);
    }
b[0]=1;
b[1]=2;
mp[1]=1;
mp[2]=1;
int k=2;
for(i=3;i<=size;i+=2)
    if(a[i]==0)
        {
        b[k++]=i;
        mp[i]=1;
        }
return 0;
}

int main()
{
seive();
char c[100];
int i,j;
while(gets(c))
    {
    int sum=0;
    int len=strlen(c);
    for(i=0;i<len;i++)
        {
        if(c[i]>='a'&&c[i]<='z')
            sum+=c[i]-'a'+1;
        else if(c[i]>='A'&&c[i]<='Z')
            sum+=c[i]-'A'+27;
        }
    if(mp[sum]==1)
        cout<<"It is a prime word."<<endl;
    else if(mp[sum]==0&&sum>0)
        cout<<"It is not a prime word."<<endl;
    }
return 0;
}
