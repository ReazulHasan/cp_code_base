#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string s1,s2;
pair<int,int> pa;
vector<pair<int,int> >va,vb;

int arrang(int x,int y)
{
if(x<y)
    {
    pa.first=x;
    pa.second=y;
    va.push_back(pa);
    }
else
    {
    pa.first=y;
    pa.second=x;
    va.push_back(pa);
    }
return 0;
}

int brrang(int x,int y)
{
if(x<y)
    {
    pa.first=x;
    pa.second=y;
    vb.push_back(pa);
    }
else
    {
    pa.first=y;
    pa.second=x;
    vb.push_back(pa);
    }
return 0;
}

int main()
{
int i,j,k,cas,temp;
cin>>cas;
while(cas--)
    {
    cin>>s1>>s2;
    int x,y;
    x=s1[0]-'0'; y=s1[1]-'0';
    arrang(x,y);
    x=s1[2]-'0'; y=s1[4]-'0';
    arrang(x,y);
    x=s1[3]-'0'; y=s1[5]-'0';
    arrang(x,y);
    x=s2[0]-'0'; y=s2[1]-'0';
    brrang(x,y);
    x=s2[2]-'0'; y=s2[4]-'0';
    brrang(x,y);
    x=s2[3]-'0'; y=s2[5]-'0';
    brrang(x,y);
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    int flg=0;
    for(i=0;i<3;i++)
        if(va[i].first!=vb[i].first||va[i].second!=vb[i].second)
            {
            flg=1;
            break;
            }
    if(flg==0)
        cout<<"Equal"<<endl;
    else
        cout<<"Not Equal"<<endl;
    va.clear(); vb.clear();
    s1.clear(); s2.clear();
    }
return 0;
}
