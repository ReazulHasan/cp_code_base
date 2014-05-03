#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;

int main()
{
int n,i,j,k;
while(cin>>n&&n)
    {
    int x,y;
    x=n;
    deque<int> dq;
    vector<int> v;
    if(n>1)
    {
    for(i=1;i<=n;i++)
        dq.push_back(i);
    while(!dq.empty())
        {
        if(!dq.empty())
            {
            x=dq.front();
            dq.pop_front();
            }
        if(dq.empty())
            break;
        if(!dq.empty())
            {
            y=dq.front();
            dq.pop_front();
            }
        v.push_back(x);
        dq.push_back(y);
        }
    }
    cout<<"Discarded cards:";
    int len=v.size();
    if(len>0)
        cout<<" "<<v[0];
    for(i=1;i<len;i++)
        cout<<", "<<v[i];
    cout<<endl;
    cout<<"Remaining card: ";
   /* int last=dq.front();
    dq.pop_front();*/
    cout<<x<<endl;
    }
return 0;
}
