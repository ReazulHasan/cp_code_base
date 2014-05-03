#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
int i,j,k;
string s;
char a[100];
while(cin>>s)
    {
    int len=s.size();
    if(len==1&&s[0]=='#')
        break;
    for(i=0;i<len;i++)
        a[i]=s[i];
    if(next_permutation(a,a+len))
        {
        for(i=0;i<len;i++)
            cout<<a[i];
        cout<<endl;
        //cout<<a<<endl;
        }
    else
        cout<<"No Successor"<<endl;
    }
return 0;
}
