#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
char a[1000],c,f[10];
map<char,int> mp1;
map<int,char> mp2;
int n,i,j,b[1000];
cin>>n;
gets(f);
//puts(f);
for(j=0;j<n;j++)
    {
    gets(a);
    for(i=0;i<strlen(a);i++)
        if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
            {
            if(a[i]>='a'&&a[i]<='z')
                a[i]=a[i]-32;
            mp1[a[i]]++;
            }
    }
int k=0;
for(c='A';c<='Z';c++)
    if(mp1[c]!=0)
        b[k++]=mp1[c];
sort(b,b+k);
for(i=k-1;i>=0;i--)
    for(c='A';c<='Z';c++)
        {
        if(mp1[c]==b[i])
            {
            cout<<c<<" "<<b[i]<<endl;
            mp1[c]=-1;
            }
        }
return 0;
}
