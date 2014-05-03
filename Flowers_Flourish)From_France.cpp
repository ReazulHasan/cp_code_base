#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,n;
string s;
while(getline(cin,s))
    {
    if(s[0]=='*')
        break;
    int len=s.size(),fl=1;
    char ch=toupper(s[0]);
    for(i=1;i<len;i++)
        if(s[i-1]==' ')
            if(toupper(s[i])!=ch)
                {
                fl=0;
                break;
                }
    if(fl)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
    }
return 0;
}
