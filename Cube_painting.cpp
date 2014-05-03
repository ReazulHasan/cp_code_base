#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

struct ss{
    char col;
    int val;
    };

int main()
{
int i,j,k,l;
ss t;
string s,s1,s2;
while(cin>>s)
    {
    vector<ss> v1,v2;
    map<char,int> mp1,mp2;
    s1.clear(); s2.clear();
    for(i=0;i<6;i++)
        {
        mp1[s[i]]++;
        t.col=s[i];
        t.val=i;
        v1.push_back(t);
        s1+=s[i];
        }
    for(i=6;i<12;i++)
        {
        mp2[s[i]]++;
        t.col=s[i];
        t.val=i%6;
        v2.push_back(t);
        s2+=s[i];
        }
    if(mp1['r']==mp2['r']&&mp1['g']==mp2['g']&&mp1['b']==mp2['b']);
        {
        int fl=0;
        for(i=0;i<6;i++)
            {
            if(v1[i].col==v2[i].col&&v1[i].val==v2[i].val)
                continue;
            else
                fl=1;
            }
        if(fl==0)
            cout<<"TRUE"<<endl;
        else
            {
            int flg=1;
            while(next_permutation(v2.begin(),v2.end()))
                {
                fl=0;
                for(i=0;i<6;i++)
                    {
                    if(v1[i].col==v2[i].col&&v1[i].val==v2[i].val)
                        continue;
                    else
                        {
                        fl=1;
                        break;
                        }
                    }
                if(fl==0)
                    {
                    flg=0;
                    cout<<"TRUE"<<endl;
                    break;
                    }
                }
            if(flg)
                cout<<"False"<<endl;
            }
        }
    else
        cout<<"FALSE"<<endl;
    }
return 0;
}
