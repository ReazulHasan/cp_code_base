#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
int t,i,j,k,cas=0;
char a[100],z[10];
cin>>t;
gets(z);
while(t--)
    {
    cas++;
    map<char,int> mp;
    map<char,int> flag;
    int p[100],q[100];
    gets(a);
    int len=strlen(a);
    //cout<<len<<endl;
    k=0;
    int m=0;
    for(i=2;i<=len;i++)
        p[m++]=i;
    for(i=0;i<len;i++)
        mp[a[i]]++;
    k=0;
    for(i=0;i<len;i++)
        if(mp[a[i]]>1&&flag[a[i]]==0)
            {
            //cout<<a[i]<<" "<<mp[a[i]]<<endl;
            flag[a[i]]=1;
            int x=mp[a[i]];
            while(x>=2)
                {
                q[k++]=x;
                x--;
                }
            }
    unsigned long long res=1,div=1;
    //unsigned long long v=1;
    for(i=0;i<m;i++)
        res*=p[i];
    for(j=0;j<k;j++)
        div*=q[j];
    //cout<<res<<" "<<div<<endl;
    res/=div;
    cout<<"Data set "<<cas<<": "<<res<<endl;
    }
return 0;
}
