#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
int i,j,k,man,wom,cas=0;
while(cin>>man>>wom)
    {
    cas++;
    if(!man&&!wom)
        break;
    int minx=100000,x;
    for(i=0;i<man;i++)
        {
        cin>>x;
        if(x<minx)
            minx=x;
        }
    for(i=0;i<wom;i++)
        cin>>x;
    cout<<"Case "<<cas<<": ";
    if(man>wom)
        cout<<man-wom<<" "<<minx<<endl;
    else
        cout<<"0"<<endl;
    }
return 0;
}
