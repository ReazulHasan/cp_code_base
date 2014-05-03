//Bismillahir Rahmanir Rahim.
//In this code, every month consists of 30 days & leap years are not considered.
//Vai, jototuku parlam korlam, kono case a jodi atkay, amare boilen plz.

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int born[100],now[100];

int calculate_age()
{
int i,j,k,dd1,dd,mm1,mm,yy;
if(born[2]<now[2])
    {
    yy=now[2]-born[2]-1;
    mm1=12-born[1]-1;
    mm=mm1+now[1];
    if(mm<0)
        mm=0;
    dd1=30-born[0];
    dd=dd1+now[0];
    if(dd>=30)
        {
        mm++;
        dd%=30;
        }
    if(mm>=12)
        {
        yy++;
        mm%=12;
        }
    }
else if(born[2]==now[2])
    {
    yy=0;
    if(now[1]>born[1])
        {
        mm=now[1]-born[1]-1;
        dd=now[0]+30-born[0];
        if(dd>=30)
            {
            mm++;
            dd%=30;
            }
        }
    else if(now[1]==born[1])
        {
        mm=0;
        dd=now[0]-born[0];
        }
    }
cout<<"Your Age Is:"<<endl;
cout<<"       "<<yy<<" year(s) & "<<mm<<" month(s) & "<<dd<<" day(s)."<<endl;
return 0;
}

int main()
{
int i,j,k,cas;
cin>>cas;      //Enter the no. of tests
while(cas--)
    {
    for(i=0;i<3;i++)
        cin>>born[i];  //enter your birth date in format dd mm yy
    for(i=0;i<3;i++)
        cin>>now[i];   //enter todays date in format dd mm yy
    calculate_age();
    }
return 0;
}
