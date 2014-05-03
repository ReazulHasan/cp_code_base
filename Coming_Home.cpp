#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
int i,j,k,cas,kas=0;
cin>>cas;
while(cas--)
    {
    kas++;
    string s1;
    int hh,mm,bus,minx=98798798;
    cin>>bus>>s1;
    hh=(s1[0]-'0')*10+(s1[1]-'0');
    hh*=60;
    mm=(s1[3]-'0')*10+s1[4];
    int pres=hh+mm,trav;
    for(i=0;i<bus;i++)
        {
        cin>>s1>>trav;
        int arrive=((s1[0]-'0')*10+(s1[1]-'0'))*60+((s1[3]-'0')*10+s1[4]);
        int time;
        if(arrive<pres)
            time=24*60-(pres-arrive)+trav;
        else
            time=arrive-pres+trav;
        if(time<minx)
            minx=time;
        }
    cout<<"Case "<<kas<<": "<<minx<<endl;
    }
return 0;
}
