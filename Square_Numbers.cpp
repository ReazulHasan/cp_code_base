#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
vector<int> v;
vector<int>::iterator lo,hi;
int i,j,a,b;
for(i=1;i<=100000;i++)
    {
    if(ceil(sqrt(i))==floor(sqrt(i)))
        v.push_back(i);
    }
sort(v.begin(),v.end());
/*for(i=0;i<100;i++)
    cout<<v[i]<<" ";
cout<<endl;*/
while(cin>>a>>b&&a&&b)
    {
    lo=lower_bound(v.begin(),v.end(),a);
    hi=upper_bound(v.begin(),v.end(),b);
    int x=lo-v.begin();
    int y=hi-v.begin();
    cout<<y-x<<endl;
    }
return 0;
}
