#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int main()
{
int i,j,k,cas,flg=0;
string a,b,c,d;
cin>>cas;
while(cas--)
    {
    cin>>a>>b;
    if(flg) cout<<endl;
    flg=1;
    int lena=a.size(),lenb=b.size(),zer=1;
    cout<<a<<" "<<b<<endl;
    while(1)
        {
        zer=1;
        c.clear(); d.clear();
        for(i=0;i<lena;i++)
            {
            if(a[i]!=b[i])
                c+='1';
            else c+='0';
            if(a[i]=='0'||b[i]=='0')
                d+='0';
            else
                {
                d+='1';
                zer=0;
                }
            }
        a.clear(); b.clear();
        for(i=0;i<lena;i++)
            a+=c[i];
        for(i=1;i<lena;i++)
            b+=d[i];
        b+='0';
        if(d[0]=='1')
            {
            cout<<a<<" overflow"<<endl;
            break;
            }
        else
            cout<<a<<" "<<b<<endl;
        if(zer)
            break;
        }
    }
return 0;
}
