#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
int ind=1;
string s,s1,s2,s3,s4,s5;
char i,j,k,l,m;
map<string,int> mp;
for(i='a';i<='z';i++)
    {
    s=i;
    mp[s]=ind++;
    }
s.clear();
for(i='a';i<='z';i++)
    {
    s=i;
    for(j=i+1;j<='z';j++)
        {
        s1+=s;
        s1+=j;
        mp[s1]=ind++;
        s1.clear();
        }
    }
for(i='a';i<='z';i++)
    {
    for(j=i+1;j<='z';j++)
        {
        for(k=j+1;k<='z';k++)
            {
            s=i;
            s+=j;
            s+=k;
            mp[s]=ind++;
            s.clear();
            }
        }
    }
s.clear();
for(i='a';i<='z';i++)
    {
    for(j=i+1;j<='z';j++)
        {
        for(k=j+1;k<='z';k++)
            {
            for(l=k+1;l<='z';l++)
                {
                s=i;
                s+=j;
                s+=k;
                s+=l;
                mp[s]=ind++;
                s.clear();
                }
            }
        }
    }
s.clear();
for(i='a';i<='z';i++)
    {
    for(j=i+1;j<='z';j++)
        {
        for(k=j+1;k<='z';k++)
            {
            for(l=k+1;l<='z';l++)
                {
                for(m=l+1;m<='z';m++)
                    {
                    s=i;
                    s+=j;
                    s+=k;
                    s+=l;
                    s+=m;
                    mp[s]=ind++;
                    s.clear();
                    }
                }
            }
        }
    }
while(cin>>s)
    cout<<mp[s]<<endl;
return 0;
}
