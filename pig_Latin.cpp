#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char a[10000009];

int vowel(char c)
{
if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
    return 1;
return 0;
}

int main()
{
int i,j,k;
while(gets(a))
    {
    char c;
    int len=strlen(a);
    a[len]=' ';
    //cout<<len<<endl;
    i=0;
    while(i<len)
        {
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
            {
            if(vowel(a[i]))
                c='0';
            else
                {
                c=a[i];
                i++;
                }
            while(i<len&&a[i]!=' '&&a[i]!='.')
                {
                cout<<a[i];
                i++;
                }
            if(c=='0')
                cout<<"ay";
            else
                cout<<c<<"ay";
            if(a[i]=='.')
                {
                cout<<".";
                i++;
                }
            else if(a[i]==' '&&i<len)
                {
                cout<<" ";
                i++;
                }
            }
        else
            {
            while(a[i]!=' ')
                {
                cout<<a[i];
                i++;
                }
            if(a[i]==' '&&i<len)
                {
                cout<<' ';
                i++;
                }
            }
        }
    //cout<<"x";
    cout<<endl;
    for(i=0;i<=len;i++)
        a[i]='\0';
    }
return 0;
}
