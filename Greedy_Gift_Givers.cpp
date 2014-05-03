#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
using namespace std;

int res[10000];

int main()
{
int i,j,pep,fl=0;
while(cin>>pep)
    {
    map<string,int> mpstr;
    map<int,string> mpint;
    string s,s1;
    int tot,n;
    for(i=1;i<=pep;i++)
        {
        cin>>s;
        mpstr[s]=i;
        mpint[i]=s;
        }
    for(i=1;i<=pep;i++)
        {
        cin>>s>>tot>>n;
        if(n>0)
            {
            res[mpstr[s]]-=tot;
            res[mpstr[s]]+=tot%n;
            for(j=1;j<=n;j++)
                {
                cin>>s1;
                res[mpstr[s1]]+=tot/n;
                }
            }
        }
    if(fl) cout<<endl;
    fl=1;
    for(i=1;i<=pep;i++)
        cout<<mpint[i]<<" "<<res[i]<<endl;
    mpstr.clear(); mpint.clear(); s.clear(); s1.clear();
    for(i=0;i<=pep;i++)
        res[i]=0;
    }
return 0;
}
