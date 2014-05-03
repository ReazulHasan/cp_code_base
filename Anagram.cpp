#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

char a[5000];
vector<string> res;
map<string,int> mp;
map<char,int> mpfl;
map<string,int> mpchar;
int coun=0;

int permut(int star,int n)
{
int i,j,k;
coun++;
if(star==n)
    {
    //coun++;
    string s1;
    s1.clear();
    for(i=0;i<n;i++)
        s1+=a[i];
    //cout<<s1<<endl;
    if(mp[s1]==0)
        {
        res.push_back(s1);
        mp[s1]=1;
        }
    }
else
    {
    for(i=star;i<n;i++)
        {
        if(a[star]!=a[i]||i==star)
            {
            //cout<<a[star]<<" "<<a[i]<<endl;
            char temp=a[star];
            a[star]=a[i];
            a[i]=temp;
            string sx,sy;
            sx.clear(); sy.clear();
            sx+=a[i]; sx+=a[star];
            sy+=a[star]; sy+=a[i];
            if(mpchar[sx]==0&&mpchar[sy]==0)
                {
                mpchar[sx]=1; mpchar[sy]=1;
                permut(star+1,n);
                }
            a[i]=a[star];
            a[star]=temp;
            }
        }
    }
return 0;
}

int main()
{
int i,j,k,cas;
string s;
scanf("%d",&cas);
while(cas--)
    {
    scanf("%s",&s);
    //cin>>s;
    mp.clear();
    mpfl.clear();
    mpchar.clear();
    int len=s.size(),hm=0;
    for(i=0;i<len;i++)
        a[i]=s[i];
    coun=0;
    sort(a,a+len);
    permut(0,len);
    sort(res.begin(),res.end());
    int ln=res.size();
    cout<<coun<<endl;
    for(i=0;i<ln;i++)
        printf("%s\n",res[i]);
        //cout<<res[i]<<endl;
    //cout<<ln<<endl;
    res.clear();
    }
return 0;
}
