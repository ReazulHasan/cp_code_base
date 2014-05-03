#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
float x,y,a[400];
int i=0,j,flag=0,count=0,fig=0;
char c;
cin>>c;
while(c!='*')
    {
    if(c=='r')
        cin>>a[i++]>>a[i++]>>a[i++]>>a[i++];
    cin>>c;
    }
cin>>x>>y;
while(fabs(x-9999.9)>0.001||fabs(y-9999.9)>0.001)
    {
    j=0;
    count++;
    while(j<i)
        {
        fig++;
        if(x>a[j]&&x<a[j+2]&&y<a[j+1]&&y>a[j+3])
            {
            cout<<"Point "<<count<<" is contained in figure "<<fig<<endl;
            flag=1;
            }
        j+=4;
        }
        if(flag==0)
            cout<<"Point "<<count<<" is not contained in any figure"<<endl;
        flag=0; fig=0;
    cin>>x>>y;
    }
return 0;
}
