#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

string s[500];
int ro[]={-1,1,0,0};
int co[]={0,0,-1,1};
int r,c,coun=0;

int dot(int a,int b)
{
int i,j,k;
s[a][b]='.';
for(i=0;i<4;i++)
    {
    int x=a+ro[i];
    int y=b+co[i];
    if(x>=0&&x<r&&y>=0&&y<c)
        if(s[x][y]=='X')
            dot(x,y);
    }
return 0;
}

int flood(int a,int b)
{
int i,j,k;
s[a][b]='.';
cout<<"a: "<<a<<", b: "<<b<<endl;
for(i=0;i<4;i++)
    {
    int x=a+ro[i];
    int y=b+co[i];
    if(x>=0&&x<r&&y>=0&&y<c)
        {
        if(s[x][y]=='*')
            flood(x,y);
        if(s[x][y]=='X')
            {
            coun++;
            dot(x,y);
            }
        }
    }
return 0;
}

int main()
{
int i,j,k,cas=0;
while(cin>>r>>c)
    {
    cas++;
    if(!r&&!c)
        break;
    vector<int> res;
    for(i=0;i<r;i++)
        cin>>s[i];
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            {
            cout<<s[i][j];
            if(s[i][j]=='*')
                {
                cout<<"coun "<<coun<<endl;
                coun=0;
                flood(i,j);
                if(coun)
                    res.push_back(coun);
                }
            }
        cout<<endl;
        }
    sort(res.begin(),res.end());
    int len=res.size();
    cout<<"Throw "<<cas<<endl;
    if(len>0)
        cout<<res[0];
    for(i=1;i<len;i++)
        cout<<" "<<res[i];
    cout<<endl;
    }
return 0;
}
