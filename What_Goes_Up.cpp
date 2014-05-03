#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int a[1000000],n,coun[1000000],prev[1000000];
stack<int> st;

int LIS()
{
int i,j,k;
int hi=0,last=0;
//cout<<n<<endl;
for(i=1;i<n;i++)
    {
    int max=0,child=-1;
    for(j=i-1;j>=0;j--)
        if(a[i]>a[j])
            if(coun[j]>max)
                {
                max=coun[j];
                child=j;
                }
    coun[i]=max+1;
    prev[i]=child;
    if(hi<coun[i])
        {
        hi=coun[i];
        last=i;
        }
    //cout<<hi<<" "<<last<<endl;
    }
cout<<hi<<endl;
cout<<"-"<<endl;
st.push(last);
while(prev[last]!=-1)
    {
    last=prev[last];
    st.push(last);
    }
//cout<<last<<" "<<prev[last]<<endl;
while(!st.empty())
    {
    int x=st.top();
    st.pop();
    cout<<a[x]<<endl;
    }
return 0;
}

int main()
{
int i,j,k;
string s;
a[0]=0;
n=1;
while(getline(cin,s))
    {
    int len=s.size();
    if(len==0)
        break;
    int flag=0,x=0;
    for(i=0;i<len;i++)
        {
        if(s[i]=='-')
            flag=1;
        else
            {
            x*=10;
            x+=(s[i]-'0');
            }
        }
    if(flag)
        x*=-1;
    a[n]=x;
    n++;
    }
//cout<<n<<endl;
/*for(i=1;i<n;i++)
    cout<<a[i]<<" ";*/
LIS();
return 0;
}
