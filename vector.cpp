#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    vector<int> v;
    int n,i,a;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        v.resize(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        for(i=0;i<n;i++)
        {
            if(i==n-1)
                cout<<v[i]<<endl;
            else
                cout<<v[i]<<" ";

        }
    }
return 0;
}
