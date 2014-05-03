#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int soundex(char ch)
{
if(ch=='B'||ch=='F'||ch=='P'||ch=='V')
    return 1;
else if(ch=='C'||ch=='G'||ch=='J'||ch=='K'||ch=='Q'||ch=='S'||ch=='X'||ch=='Z')
    return 2;
else if(ch=='D'||ch=='T')
    return 3;
else if(ch=='L')
    return 4;
else if(ch=='M'||ch=='N')
    return 5;
else if(ch=='R')
    return 6;
else
    return 0;
}

int main()
{
int i,j,k;
string s;
while(cin>>s)
    {
    int len=s.size();
    k=0;
    int x,y=0;
    while(k<len)
        {
        x=soundex(s[k]);
        if(x!=0&&x!=y)
            cout<<x;
        y=x;
        k++;
        }
    cout<<endl;
    }
return 0;
}
