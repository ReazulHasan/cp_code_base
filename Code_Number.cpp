#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

char code(char ch)
{
if(ch=='3')
    return 'E';
else if(ch=='0')
    return 'O';
else if(ch=='1')
    return 'I';
else if(ch=='4')
    return 'A';
else if(ch=='9')
    return 'P';
else if(ch=='8')
    return 'B';
else if(ch=='5')
    return 'S';
else if(ch=='7')
    return 'T';
else if(ch=='2')
    return 'Z';
else if(ch=='6')
    return 'G';
else
    return ch;
}

int main()
{
int i,j,k,cas,kas=0;
string s[200];
cin>>cas;
getline(cin,s[0]);
while(cas--)
    {
    k=0;
    while(getline(cin,s[k]))
        {
        if(s[k].size()==0)
            break;
        k++;
        }
/*    for(i=0;i<k;i++)
        cout<<s[i]<<endl;*/
    if(kas>0)
        cout<<endl;
    kas=1;
    for(i=0;i<k;i++)
        {
        int len=s[i].size();
        for(j=0;j<len;j++)
            {
            cout<<code(s[i][j]);
            }
        cout<<endl;
        }
    }
return 0;
}
