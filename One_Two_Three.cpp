#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,n,len;
string s;
cin>>n;
while(n--)
    {
    cin>>s;
    len=s.size();
    if(len==5)
        cout<<"3"<<endl;
    else if((s[0]=='o'&&s[1]=='n')||(s[0]=='o'&&s[2]=='e')||(s[1]=='n'&&s[2]=='e'))
        cout<<"1"<<endl;
    else
        cout<<"2"<<endl;
    }
return 0;
}
