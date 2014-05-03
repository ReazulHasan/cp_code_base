#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int main()
{
int i,j,k,cas,mon,dat;
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
string day[]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
//cout<<day[1]<<endl;
cin>>cas;
while(cas--)
    {
    int tot=0;
    cin>>mon>>dat;
    for(i=0;i<(mon-1);i++)
        tot+=month[i];
    tot+=dat;
    cout<<day[tot%7]<<endl;
    }
return 0;
}
