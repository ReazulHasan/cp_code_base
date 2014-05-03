#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

map<string,string> mpstr;
map<string,int> mpint;

int main()
{
int i,j,k;
string s;
mpstr["HELLO"]="ENGLISH";
mpstr["HOLA"]="SPANISH";
mpstr["HALLO"]="GERMAN";
mpstr["BONJOUR"]="FRENCH";
mpstr["CIAO"]="ITALIAN";
mpstr["ZDRAVSTVUJTE"]="RUSSIAN";

mpint["HELLO"]=1;
mpint["HOLA"]=1;
mpint["HALLO"]=1;
mpint["BONJOUR"]=1;
mpint["CIAO"]=1;
mpint["ZDRAVSTVUJTE"]=1;

int coun=0;

while(cin>>s)
    {
    coun++;
    if(s[0]=='#')
        break;
    if(mpint[s]==1)
        cout<<"Case "<<coun<<": "<<mpstr[s]<<endl;
    else
        cout<<"Case "<<coun<<": "<<"UNKNOWN"<<endl;
    }
return 0;
}
