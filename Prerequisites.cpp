#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
int corse,cat,i,j,k,taken[200],a[200][200],tot,must,x;
while(cin>>corse&&corse)
    {
    map<int,int> mp;
    int flag=0;
    cin>>cat;
    for(i=0;i<corse;i++)
        {
        cin>>taken[i];
        mp[taken[i]]=1;
        }
    for(i=0;i<cat;i++)
        {
        int coun=0;
        cin>>tot>>must;
        for(j=0;j<tot;j++)
            {
            cin>>x;
            if(mp[x]==1)
                coun++;
            }
        if(coun<must)
            flag=1;
        }
    if(flag)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
    }
return 0;
}
