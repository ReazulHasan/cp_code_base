#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

int a[10000],b[10000],res[10000][10000];
char path[10000][10000];
stack<int> st;

int print_path(int r,int c)
{
int i,j;
if(r==0||c==0)
    return 0;
if(path[r][c]=='y')
    {
    //cout<<a[r-1]<<endl;
    st.push(a[r-1]);
    return print_path(r-1,c-1);
    }
else if(path[r][c]=='l')
    return print_path(r,c-1);
else
    return print_path(r-1,c);
}

int main()
{
int i,j,k,t;
string s,s1;
char inp[100],z[10];
cin>>t;
getline(cin,s1);
getline(cin,s1);
while(t--)
    {
    int ind=0;
    while(1)
        {
        getline(cin,s);
        int len=s.size();
        if(len==0)
            break;
        int x=0;
        //cout<<len<<" ";
        for(i=0;i<len;i++)
            {
            int m=s[i]-'0';
            x*=10;
            x+=m;
            }
        //cout<<x<<" ";
        a[ind++]=x;
        }
    for(i=0;i<ind;i++)
        b[i]=a[i];
    sort(b,b+ind);
    for(i=0;i<=ind;i++)
        res[0][i]==0;
    for(i=0;i<=ind;i++)
        res[i][0]=0;
    for(i=1;i<=ind;i++)
        for(j=1;j<=ind;j++)
            {
            if(a[i-1]==b[j-1])
                {
                res[i][j]=res[i-1][j-1]+1;
                path[i][j]='y';
                }
            else if(res[i-1][j]>res[i][j-1])
                {
                res[i][j]=res[i-1][j];
                path[i][j]='u';
                }
            else
                {
                res[i][j]=res[i][j-1];
                path[i][j]='l';
                }
            }
        cout<<"Max hits: "<<res[ind][ind]<<endl;
        print_path(ind,ind);
        while(!st.empty())
            {
            int now=st.top();
            st.pop();
            cout<<now<<endl;
            }
    for(i=0;i<=ind;i++)
        for(j=0;j<=ind;j++)
            {
            a[i]=0;
            b[i]=0;
            res[i][j]=0;
            path[i][j]='\0';
            }
    s.clear();
    if(t>0)
        cout<<endl;
    }
return 0;
}
