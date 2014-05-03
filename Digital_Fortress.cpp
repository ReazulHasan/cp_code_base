#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int main()
{
char a[10009],b[5];
int i,j,t;
cin>>t;
gets(b);
while(t--)
    {
    gets(a);
    int len=strlen(a);
    int x=len;
    int p=ceil(sqrt(x));
    int q=floor(sqrt(x));
    if(p==q)
        {
        for(i=0;i<p;i++)
            for(j=i;j<len;j+=p)
                cout<<a[j];
        }
    else
        cout<<"INVALID";
    //if(t>0)
        cout<<endl;
    }
return 0;
}
