#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,n,flag[100];
string s[100];
while(cin>>n&&n)
    {
    for(i=0;i<n;i++)
        {
        flag[i]=0;
        cin>>s[i];
        }
    while(1)
        {
        char maxn='0';
        for(i=0;i<n;i++)
            {
            if(maxn<s[i][0]&&flag[i]==0)
                maxn=s[i][0];
            }
        }
    }
return 0;
}
