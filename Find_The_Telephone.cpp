#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<char,int> mp;

int value()
{
mp['A']=2;
mp['B']=2;
mp['C']=2;
mp['D']=3;
mp['E']=3;
mp['F']=3;
mp['G']=4;
mp['H']=4;
mp['I']=4;
mp['J']=5;
mp['K']=5;
mp['L']=5;
mp['M']=6;
mp['N']=6;
mp['O']=6;
mp['P']=7;
mp['Q']=7;
mp['R']=7;
mp['S']=7;
mp['T']=8;
mp['U']=8;
mp['V']=8;
mp['W']=9;
mp['X']=9;
mp['Y']=9;
mp['Z']=9;
}

int main()
{
int i,j,k;
value();
char a[100];
while(gets(a))
    {
    int len=strlen(a);
    for(i=0;i<len;i++)
        {
        if(a[i]>='A'&&a[i]<='Z')
            cout<<mp[a[i]];
        else
            cout<<a[i];
        }
    cout<<endl;
    }
return 0;
}
