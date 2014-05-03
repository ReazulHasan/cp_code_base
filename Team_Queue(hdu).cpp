#include<iostream>
#include<cstdio>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<stack>
using namespace std;

int main()
{
int i,j,k,cas=0,kas,it,x,pos=0;
while(cin>>kas&&kas)
    {
    cas++;
    map<int,int> mpval,mppos,mpflag;
    priority_queue<int> pq;
    queue<int> q,qrest[10009],ans;
    deque<int> dq;
    stack<int> st;
    pos=1;
    for(i=0;i<kas;i++)
        {
        cin>>it;
        for(j=0;j<it;j++)
            {
            cin>>x;
            mpval[pos]=x;
            mppos[x]=pos;
            }
        pos++;
        }
    string s1,s2;
    while(cin>>s1)
        {
       // cout<<s1[0]<<" "<<x<<endl;
        if(s1[0]=='E')
            {
            cin>>x;
            //cout<<"E"<<" ";
            if(mpflag[mppos[x]]==0)
                {
                //cout<<"New";
                mpflag[mppos[x]]=1;
                dq.push_back(x);
                }
            else
                {
                //cout<<"old"<<endl;
                qrest[mppos[x]].push(x);
                }
            //cout<<endl;
            }
        else if(s1[0]=='D')
            {
            //cout<<s1[0]<<" D"<<endl;
            if(!dq.empty())
                {
                int now=dq.front();
                //cout<<now<<endl;
                ans.push(now);
                dq.pop_front();
                while(!qrest[mppos[now]].empty())
                    {
                    int mn=qrest[mppos[now]].front();
                    qrest[mppos[now]].pop();
                    st.push(mn);
                    }
                while(!st.empty())
                    {
                    int mn=st.top();
                    st.pop();
                    dq.push_front(mn);
                    }
                }
            }
        else if(s1[0]=='S')
            {
            //cout<<endl;
            break;
            }
        s1.clear();
        }
    cout<<"Scenario #"<<cas<<endl;
    while(!ans.empty())
        {
        int ou=ans.front();
        ans.pop();
        cout<<ou<<endl;
        }
    cout<<endl;
    }
return 0;
}
