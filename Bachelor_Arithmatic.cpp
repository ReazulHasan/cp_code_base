#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,sele,meye,cas=0;
while(cin>>sele>>meye)
    {
    cas++;
    if(!sele&&!meye)
        break;
    cout<<"Case "<<cas<<": ";
    if(sele==1)
        cout<<":-\\"<<endl;
    else if(meye>=sele)
        cout<<":-|"<<endl;
    else
        cout<<":-("<<endl;
    }
return 0;
}
