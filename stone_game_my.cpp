#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int main()
{
int n,a,i;
while(cin>>n&&n)
    {
    int res=0;
    for(i=0;i<n;i++)
        {
        cin>>a;
        res^=a;
        }
    if(res==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    }
}
