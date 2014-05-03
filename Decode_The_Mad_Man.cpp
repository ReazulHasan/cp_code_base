#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int decode(int x)
{
if(x==' ')
    cout<<" ";
else if(x=='e'||x=='E')
    cout<<"q";
else if(x=='d'||x=='D')
    cout<<"a";
else if(x=='c'||x=='C')
    cout<<"z";
else if(x=='r'||x=='R')
    cout<<"w";
else if(x=='f'||x=='F')
    cout<<"s";
else if(x=='v'||x=='V')
    cout<<"x";
else if(x=='t'||x=='T')
    cout<<"e";
else if(x=='g'||x=='G')
    cout<<"d";
else if(x=='b'||x=='B')
    cout<<"c";
else if(x=='y'||x=='Y')
    cout<<"r";
else if(x=='h'||x=='H')
    cout<<"f";
else if(x=='n'||x=='N')
    cout<<"v";
else if(x=='u'||x=='U')
    cout<<"t";
else if(x=='j'||x=='J')
    cout<<"g";
else if(x=='m'||x=='M')
    cout<<"b";
else if(x=='i'||x=='I')
    cout<<"y";
else if(x=='k'||x=='K')
    cout<<"h";
else if(x==','||x=='<')
    cout<<"n";
else if(x=='o'||x=='O')
    cout<<"u";
else if(x=='l'||x=='L')
    cout<<"j";
else if(x=='.'||x=='>')
    cout<<"m";
else if(x=='p'||x=='P')
    cout<<"i";
else if(x==';'||x==':')
    cout<<"k";
else if(x=='['||x=='{')
    cout<<"o";
else if(x=='\''||x=='"')
    cout<<"l";
else if(x==']'||x=='}')
    cout<<"p";
else if(x=='/'||x=='?')
    cout<<",";
return 0;
}

int main()
{
int i,j,k;
string s;
getline(cin,s);
int len=s.size();
for(i=0;i<len;i++)
    decode(s[i]);
cout<<endl;
return 0;
}
