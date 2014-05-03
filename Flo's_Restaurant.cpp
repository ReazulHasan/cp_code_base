#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

int main()
{
int i,j,k,cas,tw,fur,sex;
while(cin>>tw>>fur>>sex)
    {
    vector<int> v[10];
    int flg[12][109],mn[10];
    for(i=0;i<10;i++)
        for(j=0;j<100;j++)
            flg[i][j]=0;
    int star=8*60;
    if(tw==0&&fur==0&&sex==0)
        break;
    for(i=0;i<tw;i++)
        v[2].push_back(star);
    for(i=0;i<fur;i++)
        v[4].push_back(star);
    for(i=0;i<sex;i++)
        v[6].push_back(star);
    int x,coun=0;
    string s1;
    while(cin>>s1)
        {
        if(s1[0]=='#')
            break;
        cin>>x;
        int hour=((s1[0]-'0')*10+s1[1]-'0')*60+(s1[3]-'0')*10+(s1[4]-'0');
        if(hour>=8*60&&hour<=22*60)
        {
        if(x<=2)
            {
            int len2=v[2].size(),flag1=0;
            for(i=0;i<len2;i++)
                if(v[2][i]<=hour)
                    {
                    v[2][i]=hour+30;
                    flag1=1;
                    if(v[2][i]<23*60)
                    coun+=x;
                    break;
                    }
            if(flag1==0)
            for(i=0;i<len2;i++)
                if(v[2][i]<=hour+30)
                    {
                    v[2][i]+=30;
                    if(v[2][i]<23*60)
                    coun+=x;
                    break;
                    }
                }
        if(x<=4&&x>2)
            {
            int len4=v[4].size(),flag2=0;
            for(i=0;i<len4;i++)
                if(v[4][i]<=hour)
                    {
                    v[4][i]=hour+30;
                    flag2=1;
                    if(v[4][i]<23*60)
                    coun+=x;
                    break;
                    }
            if(flag2==0)
            for(i=0;i<len4;i++)
                if(v[4][i]<=hour+30)
                    {
                    v[4][i]+=30;
                    if(v[4][i]<23*60)
                    coun+=x;
                    break;
                    }
            }
        if(x<=6&&x>4)
            {
            int len6=v[6].size(),flag3=0;
            for(i=0;i<len6;i++)
                if(v[6][i]<=hour)
                    {
                    v[6][i]=hour+30;
                    flag3=1;
                    if(v[6][i]<23*60)
                    coun+=x;
                    break;
                    }
            if(flag3==0)
            for(i=0;i<len6;i++)
                if(v[6][i]<=hour)
                    {
                    v[6][i]+=30;
                    if(v[6][i]<23*60)
                    coun+=x;
                    break;
                    }
            }
        }
        }
    cout<<coun<<endl;
    }
return 0;
}
