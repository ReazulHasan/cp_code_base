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

ll ret[3000];

int main()
{
int i,j,k,cas;
string s;
cin>>cas;
while(cas--)
    {
    cin>>s;
    int len=s.size();
    for(i=0;i<=len;i++)
        ret[i]=0;
    for(i=len-1;i>=0;i--)
        {
        ll num=0;
        for(j=i;j<len;j++)
            {
            num*=10;
            num+=s[j]-'0';
            if(num>2147483647)
                break;
            ret[i]=max(ret[i],num+ret[j+1]);
            }
        }
    cout<<ret[0]<<endl;
    }
return 0;
}
