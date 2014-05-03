#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
int i,j,k=0;
long long fem=1,mal=1,tot=2;
long long vtot[100],vmal[100];
vtot[0]=1; vmal[0]=0;
while(tot<1000000000000000LL)
    {
    k++;
    tot=fem+mal;
    vtot[k]=tot;
    vmal[k]=mal;
    fem=mal+1;
    mal=tot;
    }
//cout<<k<<endl;
while(cin>>k)
    {
    if(k==-1)
        break;
    cout<<vmal[k]<<" "<<vtot[k]<<endl;
    }
return 0;
}
