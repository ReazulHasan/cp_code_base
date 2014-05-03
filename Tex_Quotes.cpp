#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
int i,j;
//char a[10000],b[10000],c;
char b[100000];
string s1,a;
while(getline(cin,s1))
    {
    a+=s1;
    while(1)
        {
        getline(cin,s1);
        if(s1.size()==0)
            break;
        else
            a+="\n";
        a+=s1;
        }
    int flag1=0,flag2=0;
    j=0;
    for(i=0;i<a.size();i++)
        {
        if((a[i]=='"')&flag1==0)
            {
            b[j++]='`';
            b[j++]='`';
            flag1=1;
            }
        else if(a[i]=='"'&&flag1==1)
            {
            b[j++]='\'';
            b[j++]='\'';
            flag1=0;
            }
        else
            b[j++]=a[i];
        }
        puts(b);
    for(i=0;i<100000;i++)
        b[i]='\0';
    s1.clear(); a.clear();
    }
return 0;
}
