#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
int i,j,k;
string sf,sl,word;
vector<int> vf,vl;
map<string,int> mp;
map<int,string> mpi;
while(getline(cin,sf))
    {
    int ind=1;
    int lenf=sf.size();
    i=0;
    while(i<lenf)
        {
        while(sf[i]==' '&&i<lenf)
            i++;
        while(((sf[i]>='a'&&sf[i]<='z')||(sf[i]>='A'&&sf[i]<='Z'))&&i<lenf)
            {
            word+=sf[i];
            i++;
            }
        if(mp[word]==0)
            {
            mp[word]=ind;
            mpi[ind]=word;
            vf.push_back(ind);
            ind++;
            }
        else
            vf.push_back(mp[word]);
        word.clear();
        while(sf[i]==' '&&i<lenf)
            i++;
        while(sf[i]<'A'||(sf[i]>'Z'&&sf[i]<'a')||sf[i]>'z'&&i<lenf&&sf[i]!=' ')
            {
            string ch;
            ch.clear();
            ch+=sf[i];
            if(mp[ch]==0)
                {
                mp[ch]=ind;
                mpi[ind]=word;
                vf.push_back(ind);
                ind++;
                }
            else
                vf.push_back(mp[ch]);
            i++;
            }
            while(sf[i]==' '&&i<lenf)
                i++;
        }
    int ln=vf.size();
    for(i=0;i<ln;i++)
        {
        int x=vf[i];
        cout<<mpi[x]<<" "<<vf[i]<<", ";
        }
    }
return 0;
}
