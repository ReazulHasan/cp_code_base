#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;

int main()
{
int i,j,k;
string s;
while(cin>>s)
    {
    if(s[0]=='E')
        break;
    int len=s.size();
    int num=len,coun=0;
    if(num==1&&s[0]=='1')
        {
        cout<<"1"<<endl;
        continue;
        }
    while(num>1)
        {
        coun++;
        int x=(int)log10(num)+1;
        num=x;
        }
    cout<<coun+2<<endl;
    }
return 0;
}
