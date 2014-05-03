#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int i,j,k,flag=0;
string s,s1;
s.clear();
while(getline(cin,s1))
    {
    while(1)
        {
        if(s1.length()==0)
            break;
        else
            {
            s+=s1;
            int q=(s1.size())-1;
            //q--;
            if(s1[q]!='!')
                s+="!";
            s1.clear();
            getline(cin,s1);
            }
        }
        //cout<<s<<endl;
        int sz=s.length();
        int n=0;
        if(flag)
            cout<<endl;
        flag=1;
        for(i=0;i<sz;)
        {
        while(s[i]>='0'&&s[i]<='9')
            {
            n+=s[i]-'0';
            i++;
            }
        if(s[i]=='!')
            {
            cout<<endl;
            //fl=1;
            }
        else if(s[i]=='b')
            for(j=0;j<n;j++)
                cout<<" ";
        else if((s[i]>='A'&&s[i]<='Z')||s[i]=='*')
            for(j=0;j<n;j++)
                cout<<s[i];
        n=0;
        i++;
        }
    s.clear(); s1.clear();
    }
return 0;
}
