#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k;
map<string,int> mp;
string s;
while(cin>>s)
    {
    if(s[0]=='#')
        break;
    mp[s]+=1;
    }
vector<string> v,now;
char ch;
ch=getchar();
while(ch=getchar())
    {
    map<string,int> chk;
    v.clear();
    if(ch=='#')
        break;
    s.clear(); s+=ch;
    if(chk[s]==0) v.push_back(s),chk[s]=1;
    while((ch=getchar())!='\n')
        {
        if(ch==' ')
            continue;
        int len=v.size();
        for(i=0;i<len;i++)
            {
            s.clear();
            s=v[i];
            s+=ch;
            sort(s.begin(),s.end());
            if(chk[s]==0) v.push_back(s),chk[s]=1;
            }
        s.clear();
        s+=ch;
        if(chk[s]==0) v.push_back(s),chk[s]=1;
        }
    sort(v.begin(),v.end());
    int len=v.size(),coun=0;
    for(i=0;i<len;i++)
        {
        //cout<<v[i]<<endl;
        s=v[i];
        //cout<<s<<endl;
        if(mp[s]!=0) coun+=mp[s];
        while(next_permutation(s.begin(),s.end()))
            {
            //cout<<"permut: "<<s<<endl;
            if(mp[s]!=0)
                coun+=mp[s];
            }
        //cout<<endl;
        }
    cout<<coun<<endl;
    }
return 0;
}
