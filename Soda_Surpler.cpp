#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int t,i,j,e,f,c;
cin>>t;
while(t--)
    {
    cin>>e>>f>>c;
    int tot=e+f;
    int rem=0,res=0;
    while(tot>0)
        {
        tot+=rem;
        rem=tot%c;
        res+=tot/c;
        tot/=c;
        }
    cout<<res<<endl;
    }
return 0;
}
