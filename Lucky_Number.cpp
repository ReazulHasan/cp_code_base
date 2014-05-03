#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
using namespace std;

vector<long long> v;

int main()
{
long long i;
int j,k,t,cas=0,m;
for(i=1;i<=100000;i++)
    v.push_back(i*i);
cin>>t;
while(t--)
    {
    stack<long long> st;
    cas++;
    cin>>m;
    cout<<"Case "<<cas<<":";
    for(i=0;v[i]<m;i++)
        {
        long long a=v[i],b,c;
        b=sqrt(a);
        c=m-a;
        if(c%b==0)
            st.push(c);
        }
    while(!st.empty())
        {
        int paisi=st.top();
        st.pop();
        cout<<" "<<paisi;
        }
    cout<<endl;
    }
return 0;
}
