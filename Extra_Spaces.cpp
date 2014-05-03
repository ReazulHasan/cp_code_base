#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int main()
{
int i,j,k,kas,lin,cas=0;
string s[200];
cin>>kas;
while(kas--)
    {
    cas++;
    cin>>lin;
    getline(cin,s[0]);
    for(i=0;i<lin;i++)
        getline(cin,s[i]);
/*    for(i=0;i<lin;i++)
        cout<<s[i]<<endl;*/
    if(cas>1)
        cout<<endl;
    cout<<"Case "<<cas<<":"<<endl;
    for(i=0;i<lin;i++)
        {
        int len=s[i].size();
        k=0;
        while(k<len)
            {
            int flg=0;
            while(s[i][k]==' '&&k<len) k++,flg=1;
            if(flg) cout<<" ";
            while(s[i][k]!=' '&&k<len)
                {
                cout<<s[i][k];
                k++;
                }
            }
        cout<<endl;
        }
    }
return 0;
}
