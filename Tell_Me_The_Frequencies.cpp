#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

int main()
{
string s;
int i,j,k,coun=0,len=0;
while(getline(cin,s))
    {
    if(coun==0)
        coun=1;
    else
        cout<<endl;
    map<char,int> mp;
    pair<int,char> pa;
    vector<pair<int,char> >v;
    stack<int> st;
    len=s.size();
    if(len==0)
        continue;
    for(i=0;i<len;i++)
        mp[s[i]]++;
    for(i=0;i<len;i++)
        if(mp[s[i]]!=0)
            {
            pa.first=mp[s[i]];
            pa.second=s[i];
            v.push_back(pa);
            mp[s[i]]=0;
            }
    sort(v.begin(),v.end());
    int ln=v.size();
    for(i=0;i<ln;)
        {
        int x=v[i].first;
        int y=v[i].second;
        st.push(y);
        i++;
        while(!(v[i].first-x))
            {
            st.push(v[i].second);
            i++;
            }
        while(!st.empty())
            {
            int res=st.top();
            st.pop();
            cout<<res<<" "<<x<<endl;
            }
        }
    }
return 0;
}
