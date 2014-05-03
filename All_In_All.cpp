#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

#define max 1000000

int main()
{
char a[max],b[max],c[max];
while(cin>>a>>b)
    {
    int l1,l2,i;
    l1=strlen(a);
    l2=strlen(b);
    b[l2]=' ';
    int k=0,p=0,x;
    for(i=0;i<l1;i++)
        {
        char it=a[i];
        while(it!=b[k]&&b[k]!=' ')
            k++;
        if(it==b[k])
            {
            c[p++]=b[k];
            k++;
            }
        }
    x=strcmp(a,c);
    if(x==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    for(i=0;i<max;i++)
        {
        a[i]='\0';
        b[i]='\0';
        c[i]='\0';
        }
    }
return 0;
}
