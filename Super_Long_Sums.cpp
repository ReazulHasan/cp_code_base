#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
using namespace std;

int a[1000000],b[1000000];

int main()
{
int n,cas,i,j,k,fl=0;
cin>>cas;
while(cas--)
    {
    stack<int> st;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int car=0;
    for(i=n-1;i>=0;i--)
        {
        int sum=a[i]+b[i]+car;
        car=sum/10;
        int x=sum%10;
        st.push(x);
        }
    if(fl)
        cout<<endl;
    fl=1;
    while(!st.empty())
        {
        int x=st.top();
        st.pop();
        cout<<x;
        }
    cout<<endl;
    }
return 0;
}
