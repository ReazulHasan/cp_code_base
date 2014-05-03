#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
int i,j,k=0,cas;
string s1,s2;
cin>>cas;
while(cas--)
    {
    k++;
    long long nday,nmon,nyar,pday,pmon,pyar,ndin,pdin,res;
    cin>>s1>>s2;
    nday=(s1[0]-'0')*10+(s1[1]-'0');
    nmon=(s1[3]-'0')*10+(s1[4]-'0');
    nyar=(s1[6]-'0')*1000+(s1[7]-'0')*100+(s1[8]-'0')*10+(s1[9]-'0');

    pday=(s2[0]-'0')*10+(s2[1]-'0');
    pmon=(s2[3]-'0')*10+(s2[4]-'0');
    pyar=(s2[6]-'0')*1000+(s2[7]-'0')*100+(s2[8]-'0')*10+(s2[9]-'0');

    long long age;

    if(nyar>pyar)
        {
        if(nmon>pmon)
            {
            age=nyar-pyar;
            if(age<=130)
                cout<<"Case #"<<k<<": "<<age<<endl;
            else
                cout<<"Case #"<<k<<": Check birth date"<<endl;
            }
        else if(nmon==pmon)
            {
            if(nday>=pday)
                {
                age=nyar-pyar;
                if(age<=130)
                    cout<<"Case #"<<k<<": "<<nyar-pyar<<endl;
                else
                    cout<<"Case #"<<k<<": Check birth date"<<endl;
                }
            else
                {
                age=nyar-pyar-1;
                if(age<=130)
                    cout<<"Case #"<<k<<": "<<age<<endl;
                else
                    cout<<"Case #"<<k<<": Check birth date"<<endl;
                }
            }
        else
            {
            age=nyar-pyar-1;
            if(age<=130)
                cout<<"Case #"<<k<<": "<<age<<endl;
            else
                cout<<"Case #"<<k<<": Check birth date"<<endl;
            }
        }
    else if(nyar==pyar)
        {
        if(nmon>pmon)
            cout<<"Case #"<<k<<": 0"<<endl;
        else if(nmon==pmon)
            {
            if(nday>=pday)
                cout<<"Case #"<<k<<": 0"<<endl;
            else
                cout<<"Case #"<<k<<": Invalid birth date"<<endl;
            }
        else
            cout<<"Case #"<<k<<": Invalid birth date"<<endl;
        }
    else
        cout<<"Case #"<<k<<": Invalid birth date"<<endl;
    }
return 0;
}
