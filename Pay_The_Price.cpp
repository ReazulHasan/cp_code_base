#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

unsigned long long a[5000],res[3000][3000];

int main()
{
int i,j,k;
a[0]=1;
for(i=0;i<350;i++)
    res[0][i]=1;
for(i=1;i<=350;i++)
    {
    int c=i;
    for(j=0;j<350;j++)
        {
        a[j+c]+=a[j];
        unsigned long long x=a[j+c];
        res[j+c][i]=x;
        }
    }
string s;
/*for(i=0;i<20;i++)
    {
    for(j=0;j<20;j++)
        cout<<res[i][j]<<" ";
    cout<<endl;
    }*/
while(getline(cin,s))
    {
    int len=s.size();
    vector<int> v;
    for(i=0;i<len;)
        {
        int x=0,fl=0;
        while(s[i]!=' '&&i<len)
            {
            x*=10;
            x+=s[i]-'0';
            i++;
            fl=1;
            }
        if(fl)
            v.push_back(x);
        while(s[i]==' '&&i<len)
            i++;
        }
    int it=v[0];
    unsigned long long fin=0;
    int sz=v.size();
    if(sz==1)
        cout<<res[v[0]][v[0]]<<endl;
    else if(sz==2)
        {
        int ind;
        if(v[1]>it)
            ind=it;
        else
            ind=v[1];
        if(ind<=0)
            ind=0;
        cout<<res[v[0]][ind]<<endl;
        }
    else if(sz==3)
        {
        int lo=v[1];
        int hi=v[2];
        if(lo>it)
            cout<<"0"<<endl;
        else if(lo<=it&&hi>it)
            {
            hi=it;
            if(lo<=0)
                lo=0;
            if(hi<=0)
                hi=0;
            for(i=lo;i<=hi;i++)
                fin+=(res[it][i]-res[it][i-1]);
            cout<<fin<<endl;
            }
        else if(hi<=it)
            {
            if(lo<=0)
                lo=0;
            if(hi<=0)
                hi=0;
            for(i=lo;i<=hi;i++)
                fin+=(res[it][i]-res[it][i-1]);
            cout<<fin<<endl;
            }
        }
    }
return 0;
}
