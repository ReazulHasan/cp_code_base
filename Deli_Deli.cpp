#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
int n,t,i,j,k;
string s,s1,s2;
cin>>n>>t;
map<string,int> mpstr;
map<int,string> mpint;
for(i=1;i<=n;i++)
    {
    cin>>s1>>s2;
    mpstr[s1]=i;
    mpint[i]=s2;
    }
for(i=1;i<=t;i++)
    {
    cin>>s;
    if(mpstr[s])
        cout<<mpint[mpstr[s]]<<endl;
    else
        {
        int len=s.size();
        len--;
        if(s[len]=='o'||s[len]=='s'||s[len]=='x')
            cout<<s<<"es"<<endl;
        else if(s[len]=='h')
            {
            if(s[len-1]=='c'||s[len-1]=='s')
                cout<<s<<"es"<<endl;
            else
                cout<<s<<"s"<<endl;
            }
        else if(s[len]=='y')
            {
            if(s[len-1]!='a'&&s[len-1]!='e'&&s[len-1]!='i'&&s[len-1]!='o'&&s[len-1]!='u')
                {
                for(j=0;j<len;j++)
                    cout<<s[j];
                cout<<"ies"<<endl;
                }
            else
                cout<<s<<"s"<<endl;
            }
        else
            cout<<s<<"s"<<endl;
        }
    }
return 0;
}
