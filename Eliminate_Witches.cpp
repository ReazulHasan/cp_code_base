#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> v[50009];
vector<string> res;

int main()
{
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    string s,s1,s2;
    map<string,int> mp;
    int coun=0;
    cin>>s;
    int len=s.size();
    s1.clear(); s2.clear();
    for(i=0;i<len;i++)
        {
        if((s[i]=='('||s[i]==')'||s[i]==',')&&s1.size()>0)
            {
            coun++;
            mp[s1]=coun;
            res.push_back(s1);
            //cout<<s1<<endl;
            v[mp[s1]].push_back(mp[s2]);
            v[mp[s2]].push_back(mp[s1]);
            s2=s1;
            s1.clear();
            }
        else if(s[i]!='('||s[i]!=')'||s[i]!=',')
            s1+=s[i];
        }
    cout<<coun<<endl;
    for(i=0;i<coun;i++)
        cout<<res[i]<<endl;
    }
return 0;
}
