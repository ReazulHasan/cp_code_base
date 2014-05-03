#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
string s1,s;
int coun=0;
getline(cin,s);
while(1)
    {
    int k;
    if(s.size()==0)
        break;
    s+="A";
    int p=0,q=0,r=0,i=0;
    while(s[i]>='0'&&s[i]<='9')
        {
        p=p*10+(s[i]-'0');
        i++;
        }
    if(s[i]=='+')
        k=1;
    else
        k=2;
    i++;
    while(s[i]>='0'&&s[i]<='9')
        {
        q=q*10+(s[i]-'0');
        i++;
        }
    i++;
    int fl=0;
    while(s[i]>='0'&&s[i]<='9')
        {
        r=r*10+(s[i]-'0');
        i++;
        fl=1;
        }
    if(k==1)
        p=p+q;
    if(k==2)
        p=p-q;
    if(p==r&&fl==1)
        coun++;
    getline(cin,s);
    }
cout<<coun<<endl;
return 0;
}
