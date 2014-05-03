#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<stack>
using namespace std;

char a[100],b[100],c[100];
//int b[100];
vector<int> v;
stack<int> st;

int main()
{
int t,i,j,k,ln1,ln2;
cin>>t;
for(k=1;k<=t;k++)
    {
    cin>>a;
    int p=0,q=0;
    for(i=strlen(a)-1;i>=0;i--)
        b[p++]=a[i];
    int car=0;
    for(i=strlen(a)-1;i>=0;i--)
        {
        int x;
        x=(a[i]-'0')+(b[i]-'0')+car;
        cout<<"x"<<x<<endl;
        if(x<10)
            c[q++]=x+'0';
        else
            {
            c[q++]=(x%10)+'0';
            car=x/10;
            }
        }
    puts(c);
    /*while(1)
        {
        if(!ispal())
            {
            for(i=0;i<strlen(a);i++)
                {
                v.push_back(a[i]-'0');
                st.insert(a[i]-'0');
                }
            for(i=0;i<v.size();i++)
                {

                }
            }
        }*/
    }
return 0;
}
