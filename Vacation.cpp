#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
int i,j,k,cas=0;
string sf,sl,sz;
while(getline(cin,sf))
    {
    cas++;
    int res[500][500];
    if(sf[0]=='#')
        break;
    vector<int> vf,vl;
    int ind=1;
    map<char,int> mp;
    int lenf=sf.size();
    for(i=0;i<lenf;i++)
        {
        char ch=sf[i];
        if(mp[ch]==0)
            {
            mp[ch]=ind;
            vf.push_back(ind);
            ind++;
            }
        else
            vf.push_back(mp[ch]);
        }
    //getline(cin,sz);
    getline(cin,sl);
    int lenl=sl.size();
    for(i=0;i<lenl;i++)
        {
        char ch=sl[i];
        if(mp[ch]==0)
            {
            mp[ch]=ind;
            vl.push_back(ind);
            ind++;
            }
        else
            vl.push_back(mp[ch]);
        }
    int x=vf.size();
    int y=vl.size();
    for(i=0;i<=x;i++)
        res[0][i]=0;
    for(i=0;i<=y;i++)
        res[i][0]=0;
    for(i=1;i<=x;i++)
        for(j=1;j<=y;j++)
            {
            if(vf[i-1]==vl[j-1])
                res[i][j]=res[i-1][j-1]+1;
            else if(res[i-1][j]>res[i][j-1])
                res[i][j]=res[i-1][j];
            else
                res[i][j]=res[i][j-1];
            }
    //cout<<lenf<<" "<<lenl<<endl;
    cout<<"Case #"<<cas<<": you can visit at most "<<res[x][y]<<" cities."<<endl;
    sf.clear(); sl.clear();
    }
return 0;
}
