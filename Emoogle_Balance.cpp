#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
int i,j,k,n,x,cas=0;
while(cin>>n&&n)
    {
    cas++;
    int coun=0;
    for(i=0;i<n;i++)
        {
        cin>>x;
        if(!x)
            coun++;
        }
    cout<<"Case "<<cas<<": "<<(n-coun)-coun<<endl;
    }
return 0;
}
