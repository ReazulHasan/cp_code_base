#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> v[50009];
vector<string> res;
int color[50009];

int DFS(int x)
{
int i,j,k;
color[x]=1;
int len=v[x].size();
for(i=0;i<len;i++)
    if(color[v[x][i]]==0)
        {
        //cout<<x<<" "<<v[x][i]<<endl;
        printf("%d %d\n",x,v[x][i]);
        DFS(v[x][i]);
        printf("%d %d\n",v[x][i],x);
        //cout<<v[x][i]<<" "<<x<<endl;
        }
return 0;
}

int main()
{
int i,j,k,cas;
cin>>cas;
while(cas--)
    {
    string s,s1,s2,s3;
    stack<string> st;
    map<string,int> mp;
    map<int,int> mplast;
    int coun=0;
    cin>>s;
    int len=s.size(),now=0;
    s1.clear(); s2.clear();
    for(i=0;i<len;i++)
        {
        if((s[i]=='('||s[i]==')'||s[i]==',')&&s1.size()>0)
            {
            int fl=1;
            coun++;
            mp[s1]=coun;
            if(s[i]=='(')
                {
                st.push(s1);
                v[coun].push_back(coun+1);
                v[coun+1].push_back(coun);
                now++;
                fl=0;
                }
            else if(s[i]==')')
                {
                now--;
                if(!st.empty()&&now>0)
                    {
                    s3=st.top();
                    //cout<<"stck ) "<<s3<<" mp[s3]: "<<mp[s3]<<" mp[s1]: "<<mp[s1]<<" "<<s1<<endl;
                    v[mp[s3]].push_back(mp[s1]);
                    v[mp[s1]].push_back(mp[s3]);
                    st.pop();
                    fl=0;
                    }
                }
            res.push_back(s1);
           // string s3;
            if(!st.empty())
            {
            s3=st.top();
            //cout<<s3<<endl;
            if(coun>1&&mp[s3]!=mp[s1]&&fl&&mplast[mp[s3]]!=mp[s1])
                {
                mplast[mp[s3]]=mp[s1];
                v[mp[s3]].push_back(mp[s1]);
                v[mp[s1]].push_back(mp[s3]);
                }
            }
            s2=s1;
            s1.clear();
            }
        else if(s[i]!='('&&s[i]!=')'&&s[i]!=',')
            s1+=s[i];
        }
    if(coun==0)
        cout<<coun+1<<endl<<s1<<endl;
    else
        {
        cout<<coun<<endl;
        for(i=0;i<coun;i++)
            cout<<res[i]<<endl;
            //printf("%s\n",res[i]);

        for(i=0;i<=coun;i++)
            color[i]=0;
        for(i=1;i<=coun;i++)
            if(color[i]==0)
                DFS(i);
        }
    if(cas>0)
        printf("\n");
    //cout<<endl;

    /*for(i=1;i<=coun;i++)
        {
        cout<<i<<" : ";
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
        }*/

    for(i=0;i<=coun;i++)
        v[i].clear();
    res.clear();

    }
return 0;
}
