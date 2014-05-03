#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

vector<int> v,fin;
int knap[100][100009];
stack<int> st;

int print_path(int n,int tot)
{
if(n<=0||tot<=0)
    return 0;
if(knap[n][tot]!=knap[n-1][tot])
    {
    st.push(v[n]);
    fin.push_back(v[n]);
    tot=tot-v[n];
    n=n-1;
    return print_path(n,tot);
    }
else
    return print_path(n-1,tot);
}

int main()
{
int i,j,k;
string s;
while(getline(cin,s))
    {
    vector<int> inp;
    int len=s.size();
    int coun=0,tot,n;
    v.push_back(-1);
    for(i=0;i<len;)
        {
        int x=0,flag=0;
        while(s[i]!=' '&&i<len)
            {
            flag=1;
            x*=10;
            x+=s[i]-'0';
            i++;
            }
        if(flag)
            coun++;
        if(coun==1)
            tot=x;
        else if(coun==2)
            n=x;
        else
            {
            v.push_back(x);
            inp.push_back(x);
            }
        while(s[i]==' '&&i<len)
            i++;
        }
    sort(v.begin(),v.end());
    for(i=0;i<=tot;i++)
        knap[0][i]=0;
    for(i=0;i<=n;i++)
        knap[i][0]=0;
    for(i=1;i<=n;i++)
        {
        int now=v[i];
        for(j=1;j<=tot;j++)
            {
            if(j>=now)
                {
                if((now+knap[i-1][j-now])>knap[i-1][j])
                    knap[i][j]=(now+knap[i-1][j-now]);
                else
                    knap[i][j]=(knap[i-1][j]);
                }
            else
                knap[i][j]=(knap[i-1][j]);
            }
        }
    if(knap[n][tot]==0)
        cout<<"0 sum:0"<<endl;
    else
        {
        print_path(n,tot);
        int sz=fin.size();
        for(i=0;i<n;i++)
            {
            int it=inp[i];
            for(j=0;j<sz;j++)
                {
                if(it==fin[j])
                    {
                    cout<<it<<" ";
                    fin[j]=-1;
                    break;
                    }
                }
            }
        cout<<"sum:"<<knap[n][tot]<<endl;
        }
    for(i=0;i<=n;i++)
        for(j=0;j<=tot;j++)
            knap[i][j]=0;
    v.clear(); fin.clear(); inp.clear();
    }
return 0;
}
