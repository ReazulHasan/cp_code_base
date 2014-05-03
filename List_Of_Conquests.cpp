#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,cas;
string s1,s2;
map<string,int> mp;
vector<string> v;
cin>>cas;
while(cas--)
    {
    cin>>s1;
    getline(cin,s2);
    if(mp[s1]==0)
        v.push_back(s1);
    mp[s1]++;
    //cout<<s2<<endl;
    }
sort(v.begin(),v.end());
int len=v.size();
for(i=0;i<len;i++)
    cout<<v[i]<<" "<<mp[v[i]]<<endl;
return 0;
}
