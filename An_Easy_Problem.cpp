#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;

int char_to_num(char ch)
{
if(ch>='A'&&ch<='Z')
    return ch-'A'+10;
else if(ch>='a'&&ch<='z')
    return ch-'a'+36;
}

int main()
{
string s1,s2;
int i,j,k;
char ch;
while(cin>>s1)
    {
    int len=s1.size(),sum=0,maxn=0,flag=0;
    for(i=0;i<len;i++)
        {
        int x;
        if((s1[i]>='0'&&s1[i]<='9'))
            {
            x=s1[i]-'0';
            sum+=s1[i]-'0';
            }
        else if(s1[i]>='a'&&s1[i]<='z')
            {
            x=char_to_num(s1[i]);
            sum+=x;
            }
        else if(s1[i]>='A'&&s1[i]<='Z')
            {
            x=char_to_num(s1[i]);
            sum+=x;
            }
        else
            x=0;
        if(maxn<x)
            maxn=x;
        }
    if(maxn==0)
        cout<<2<<endl;
    else
        {
        for(i=maxn;i<=62;i++)
            if(sum%i==0)
                {
                flag=1;
                cout<<i+1<<endl;
                break;
                }
        if(flag==0)
            cout<<"such number is impossible!"<<endl;
        }
    //cout<<sum<<" "<<maxn<<endl;
    }
return 0;
}
