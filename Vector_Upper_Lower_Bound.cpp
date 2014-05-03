#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
vector<int> v;
int i;
for(i=1;i<60;i+=2)
    v.push_back(i);
for(i=0;i<30;i++)
    cout<<v[i]<<" ";
vector<int>::iterator lo,hi;
int it1,it2;
while(cin>>it1>>it2)
    {
    lo=lower_bound(v.begin(),v.end(),it1);
    hi=upper_bound(v.begin(),v.end(),it2);
    cout<<int(lo-v.begin())<<" "<<int(hi-v.begin())<<endl;
    }
return 0;
}
