#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
int a,b,c,i,j,k,ar1[100009],ar2[100009];
while(cin>>a>>b)
    {
    int coun=0;
    if(a==0&&b==0)
        break;
    for(i=0;i<=100005;i++)
        {
        ar1[i]=0;
        ar2[i]=0;
        }
    for(i=0;i<a;i++)
        {
        cin>>c;
        if(c<100000)
            ar1[c]=1;
        else
            ar2[c%100000]=1;
        }
    for(i=0;i<b;i++)
        {
        cin>>c;
        if(c<100000)
            if(ar1[c]==1)
                coun++;
        else
            {
            if(ar2[c%100000]==1)
                coun++;
            }
        }
    cout<<coun<<endl;
    }
return 0;
}
