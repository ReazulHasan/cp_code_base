#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
char a[100][100];
int color[100],coun=0,r,c;

int flood(int i,int j)
{
int k;
char it=a[i][j];
a[i][j]='.';
for(k=0;k<4;k++)
    {
    int x=i+p[k];
    int y=j+q[k];
    if(x>=0&&x<r&&y>=0&&y<c)
    if(a[x][y]==it)
        {
        coun++;
        flood(x,y);
        }
    }
return 0;
}

int main()
{
int i,j,k,cas=0;
while(cin>>r>>c&&r&&c)
    {
    cas++;
    pair<int,char> pa;
    vector<pair<int,char> >v;
    stack<char> st;
    for(i=0;i<r;i++)
        cin>>a[i];
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            {
            if(a[i][j]!='.')
                {
                coun=1;
                char nw=a[i][j];
                flood(i,j);
                pa.first=coun;
                pa.second=nw;
                v.push_back(pa);
                }
            }
        }
    sort(v.begin(),v.end());
    int len=v.size();
    cout<<"Problem "<<cas<<":"<<endl;
    for(i=len-1;i>=0;)
        {
        int it=v[i].first;
        st.push(v[i].second);
        i--;
        while(v[i].first==it&&i>=0)
            {
            st.push(v[i].second);
            i--;
            }
        while(!st.empty())
            {
            cout<<st.top()<<" "<<it<<endl;
            st.pop();
            }
        }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]='\0';
    v.clear();
    }
return 0;
}
