#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
int i,j,k;
ll num;
while(cin>>num)
    {
    vector<int> v;
    ll x=num;
    while(x>0)
        {
        v.push_back(x%10);
        x/=10;
        }
    sort(v.begin(),v.end());
    int len=v.size();
    for(i=0;i<len;i++)
        cout<<v[i];
    cout<<endl;
    while(next_permutation(v.begin(),v.end()))
        {
        for(i=0;i<len;i++)
            cout<<v[i];
        cout<<endl;
        }
    }
return 0;
}
