#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
int i,j,k,now,hi,lo;
while(cin>>now&&now)
    {
    hi=11; lo=0;
    char s[100];
    char shi[]="too high",slo[]="too low",son[]="right on";
    gets(s);
    gets(s);
    if(!strcmp(s,shi))
        hi=now;
    else if(!strcmp(s,slo))
        lo=now;
    else if(!strcmp(s,son))
        {
        cout<<"Stan may be honest"<<endl;
        continue;
        }
    while(cin>>now)
        {
        gets(s);
        gets(s);
        if(!strcmp(s,shi))
            {
            if(now<hi)
                hi=now;
            }
        else if(!strcmp(s,slo))
            {
            if(now>lo)
                lo=now;
            }
        else if(!strcmp(s,son))
            {
            if(now>lo&&now<hi)
                cout<<"Stan may be honest"<<endl;
            else
                cout<<"Stan is dishonest"<<endl;
            break;
            }
        }
    /*cout<<"too high "<<strcmp(s,shi)<<endl;
    cout<<"too low "<<strcmp(s,slo)<<endl;
    cout<<"right on "<<strcmp(s,son)<<endl;*/
    }
return 0;
}
