#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
string s;
int i,j,k,flg=0;
double sped=0,from,now,rem,tot=0,dis,hm;
while(getline(cin,s))
    {
    int len=s.size();
    if(len>8)
        {
        from=((s[6]-'0')*10+(s[7]-'0'))+((s[3]-'0')*10+(s[4]-'0'))*60+((s[0]-'0')*10+(s[1]-'0'))*60*60;
        if(flg)
            {
            rem=from-hm;
            tot+=(sped*rem)/3600;
            hm=from;
            }
        sped=0;
        for(i=9;i<len;i++)
            {
            double x=s[i]-'0';
            sped*=10;
            sped+=x;
            }
        //cout<<from<<" "<<sped<<endl;
        }
    else
        {
        now=((s[6]-'0')*10+(s[7]-'0'))+((s[3]-'0')*10+(s[4]-'0'))*60+((s[0]-'0')*10+(s[1]-'0'))*60*60;
        rem=now-from;
        dis=(sped*rem)/3600;
        tot+=dis;
        //cout<<rem<<" "<<tot<<endl;
        from=now;
        hm=from;
        cout<<s<<" ";
        printf("%.2lf km\n",tot);
        }
    flg=1;
    }
return 0;
}
