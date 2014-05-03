#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
map<string,int>mp;
map<string,int>::iterator it;
int i,j,n;
string s;
cin>>n;
for(i=0;i<n;i++)
    {
    cin>>s;
    for(j=0;j<s.size();j++)
        {
        if(s[j]=='0'&&s.size()>1)
            s.erase(j,1);
        else
            break;
        }
    mp["s"]=i;
    }
int t=0;
for(it=mp.begin();it!=mp.end();it++)
    {
    cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}
