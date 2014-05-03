#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int main()
{
int i,j,k,n,a[1000];
while(cin>>n&&n)
    {
    int res;
    vector<int> v;
    map<int,int> mp;
    for(i=0;i<n;i++)
        {
        cin>>k;
        v.push_back(k);
        mp[k]++;
        }
    int len=v.size();
    for(i=0;i<len;i++)
        {
        int x=v[i];
        if(mp[x]==1)
            {
            cout<<x<<endl;
            break;
            }
        }
    v.clear(); mp.clear();
    //cout<<mp2[1]<<endl;
    }
return 0;
}
