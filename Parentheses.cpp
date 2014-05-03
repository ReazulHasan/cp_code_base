#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
char a[1000],b[10];
int i,j,k,t;
cin>>t;
gets(b);
for(k=0;k<t;k++)
    {
    stack<int> st;
    gets(a);
    int flag=0;
    int len=strlen(a);
    if(len==0)
        {
        cout<<"Yes"<<endl;
        continue;
        }
    for(i=0;i<len;i++)
        {
        if(a[i]=='('||a[i]=='[')
            st.push(a[i]);
        else if(!st.empty())
            {
            if((a[i]==')'&&st.top()=='(')||(a[i]==']'&&st.top()=='['))
                st.pop();
            else
                {
                flag=1;
                break;
                }
            }
        else
            {
            flag=1;
            break;
            }
        }
    if(st.empty()&&flag==0)
        cout<<"Yes"<<endl;
    else if(flag==1||!st.empty())
        cout<<"No"<<endl;
    }
return 0;
}
