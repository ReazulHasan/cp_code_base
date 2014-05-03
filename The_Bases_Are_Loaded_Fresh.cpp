#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

char a[15],b[15];

int base1(int bas)
{
int i,res=0;
for(i=0;i<strlen(a);i++)
    {
    res*=bas;
    if(a[i]>='A')
        res+=a[i]-'0'-7;
    else
        res+=a[i]-'0';
    }
return res;
}

int main()
{
int i,j,bas1,bas2;
while(cin>>bas1>>bas2>>a)
    {
    int j=0;
    int res=base1(bas1);
    while(1)
        {
        int x=res%bas2;
        res/=bas2;
        if(x>=10)
            b[j++]=x+'0'+7;
        else
            b[j++]=x+'0';
        if(res==0)
            break;
        }
    if(j>7)
        cout<<"  ERROR"<<endl;
    else
        {
        for(i=0;i<7-j;i++)
            cout<<" ";
        for(i=j-1;i>=0;i--)
            cout<<b[i];
        cout<<endl;
        }
    }
return 0;
}

