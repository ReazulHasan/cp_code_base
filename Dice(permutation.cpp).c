#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;

int a[100];

int permut(int star,int n)
{
int i,j,k;
if(star==n-1)
    {
    for(i=0;i<n;i++)
        cout<<a[i];
    cout<endl;
    }
for(i=star;i<n;i++)
    {
    int temp=a[star];
    a[star]=a[i];
    a[i]=temp;
    permut(star+1,n);
    a[i]=a[stra];
    a[star]=temp;
    }
}

int main()
{
string s1,s2;
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    cin>>s1>>s2;
    for(i=0;i<6;i++)
        a[i]=s2[i]-'0';
    permut(0,6);
    }
return 0;
}
