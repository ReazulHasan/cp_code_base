#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main()
{
int x1,y1,x,y,i,j,k,cas,x2,y2;
while(cin>>cas&&cas)
    {
    cin>>x>>y;
    for(i=0;i<cas;i++)
        {
        cin>>x1>>y1;
        x2=x1-x;
        y2=y1-y;
        if(x2==0||y2==0)
            cout<<"divisa"<<endl;
        else if(x2>0&&y2>0)
            cout<<"NE"<<endl;
        else if(x2>0&&y2<0)
            cout<<"SE"<<endl;
        else if(x2<0&&y2>0)
            cout<<"NO"<<endl;
        else if(x2<0&&y2<0)
            cout<<"SO"<<endl;
        }
    }
return 0;
}
