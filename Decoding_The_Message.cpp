#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int main()
{
int t,i,j,k,cas=0;
string s[200],sz;
cin>>t;
getline(cin,sz);
getline(cin,sz);
while(t--)
    {
    cas++;
    k=0;
    getline(cin,s[k]);
    while(1)
        {
        int len=s[k].size();
        if(len==0)
            break;
        k++;
        getline(cin,s[k]);
        }
    int pos=0;
    if(cas>1)
        cout<<endl;
    cout<<"Case #"<<cas<<":"<<endl;
    for(i=0;i<k;i++)
        {
        int coun=0;
        pos=0;
        int len=s[i].size();
        for(j=0;j<len;)
            {
            while(s[i][j]==' '&&j<len)
                j++;
            coun=0;
            int flag=0;
            while(s[i][j]!=' '&&j<len)
                {
                if(coun==pos&&flag==0)
                    {
                    flag=1;
                    cout<<s[i][j];
                    pos++;
                    }
                coun++;
                j++;
                }
            }
        cout<<endl;
        }
    for(i=0;i<=k;i++)
        s[i].clear();
    }
return 0;
}
