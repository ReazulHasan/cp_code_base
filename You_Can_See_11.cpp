#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
char a[1009];
int i,j;
while(cin>>a)
    {
    int p=0,q=0;
    int len=strlen(a);
    if(a[0]=='0'&&len==1)
        break;
    for(i=0;i<len;i++)
        {
        cout<<a[i];
        if((i+1)%2==1)
            p+=a[i]-'0';
        else
            q+=a[i]-'0';
        }
    if((p-q)==0||(p-q)%11==0)
        cout<<" is a multiple of 11."<<endl;
    else
        cout<<" is not a multiple of 11."<<endl;
    }
return 0;
}
