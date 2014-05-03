#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
vector<int> v;
int a[10000],b,i=0,j,med;
while(cin>>a[i++])
    {
    v.resize(i+1);
    v[0]=-1;
    for(j=1;j<=i;j++)
        v[j]=a[j-1];
    //cout<<v[0];
    sort(v.begin(),v.end());
    if(i%2==0)
        {
        b=i/2;
        med=(v[b]+v[b+1])/2;
        }
    else
        {
        b=i/2+1;
        med=v[b];
        }
    cout<<med<<endl;
    }
}
