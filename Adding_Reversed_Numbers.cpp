#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,cas;
string s,s1,s2;
cin>>cas;
while(cas--)
    {
    s.clear(); s1.clear(); s2.clear();
    cin>>s;
    int fl=0;
    for(i=s.size()-1;i>=0;i--)
        {
        if(s[i]!='0')
            fl=1;
        if(fl)
        s1+=s[i];
        }
    int len1=s1.size();
    s.clear();
    cin>>s;
    fl=0;
    for(i=s.size()-1;i>=0;i--)
        {
        if(s[i]!='0')
            fl=1;
        if(fl)
        s2+=s[i];
        }
    int len2=s2.size();
    int coun=0;
    int rem=0;
    if(len1>len2)
        {
        rem=0;
        coun=len2-1;
        int hu=0,mu=0;
        for(i=len1-1;i>=0;i--)
            {
            if(coun>=0)
                {
                int x=(s1[i]-'0')+(s2[coun]-'0')+rem;
                if(x%10!=0)
                    hu=1;
                if(hu)
                    cout<<x%10;
                rem=x/10;
                coun--;
                }
            else
                {
                int x=(s1[i]-'0')+rem;
                if(hu)
                    cout<<x%10;
                else if(x%10!=0)
                    mu=1;
                if(mu)
                    cout<<x%10;
                rem=x/10;
                }
            }
        }
    else
        {
        rem=0;
        coun=len1-1;
        int hu=0,mu=0;
        for(i=len2-1;i>=0;i--)
            {
            if(coun>=0)
                {
                int x=(s1[coun]-'0')+(s2[i]-'0')+rem;
                if(x%10!=0)
                    hu=1;
                if(hu)
                    cout<<x%10;
                rem=x/10;
                coun--;
                }
            else
                {
                int x=(s2[i]-'0')+rem;
                //if(x%10!=0)hu=1,mu=1;
                if(hu)
                    cout<<x%10;
                else if(x%10!=0)
                    mu=1;
                if(mu)
                    cout<<x%10;
                rem=x/10;
                }
            }

        }
    if(rem>0)
        cout<<rem;
    cout<<endl;
    }
return 0;
}
