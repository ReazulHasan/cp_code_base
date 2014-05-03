#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<map>
#include<stack>
using namespace std;

char a[1000][1000];
int flag[1000][1000];
map<char,int> mp;
char it;
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
int ro,co;

int flood(int r,int c)
{
int i,j;
flag[r][c]=1;
//cout<<flag[r][c]<<" ";
for(i=0;i<4;i++)
    {
    int x=r+p[i];
    int y=c+q[i];
    if(x>=0&&y>=0&&x<ro&&y<co)
    if(a[x][y]==it&&flag[x][y]==0)
        {
        //cout<<x<<" "<<y<<"x y"<<endl;
        flood(x,y);
        }
    }
return 0;
}

int main()
{
int i,j,k,t,mn=0;
cin>>t;
while(t--)
    {
    mn++;
    pair<int,char> pa;
    vector<pair<int,char> >v;
    stack<char> st;
    cin>>ro>>co;
    for(i=0;i<ro;i++)
        cin>>a[i];
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            if(flag[i][j]==0)
                {
                it=a[i][j];
                //cout<<it<<" ";
                flood(i,j);
                mp[it]++;
                }
    for(char ch='a';ch<='z';ch++)
        if(mp[ch]!=0)
            {
            pa.first=mp[ch];
            pa.second=ch;
            v.push_back(pa);
            }
    sort(v.begin(),v.end());
    int len=v.size();
    cout<<"World #"<<mn<<endl;
    for(i=len-1;i>=0;)
        {
        int now=v[i].first;
        char ha=v[i].second;
        st.push(ha);
        i--;
        while(!(v[i].first-now))
            {
            st.push(v[i].second);
            i--;
            }
        while(!st.empty())
            {
            char pr=st.top();
            st.pop();
            cout<<pr<<": "<<now<<endl;
            }
        }
    for(i=0;i<ro;i++)
        for(j=0;j<co;j++)
            {
            a[i][j]='\0';
            flag[i][j]=0;
            }
    mp.clear();
    }
return 0;
}
