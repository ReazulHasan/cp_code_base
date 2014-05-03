#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k;
string s;
while(getline(cin,s))
    {
    int len=s.size();
    i=len-1;
    while(i>=0)
        {
        int num=0;
        if(s[i]>='0'&&s[i]<='9')
            {
            num*=10;
            num+=s[i]-'0';
            i--;
            num*=10;
            num+=s[i]-'0';
            if(num<=22)
                {
                i--;
                num*=10;
                num+=s[i]-'0';
                }
            i--;
            char ch=num;
            cout<<ch;
            }
        else
            {
            int x=s[i];
            while(x>0)
                {
                cout<<x%10;
                x/=10;
                }
            //cout<<s[i]<<": "<<x<<endl;
            i--;
            }
        }
    cout<<endl;
    }
return 0;
}
