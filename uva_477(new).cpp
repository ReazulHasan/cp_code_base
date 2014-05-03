#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
double x,y,a[50],b[50],c[50],d[50],cenx[50],ceny[50],r[50];
char flag[100];
int i=0,j=0,k;
while(cin>>flag[i])
    {
    if(flag[i]=='*') break;
    else if(flag[i]=='r')
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    else if(flag[i]=='c')
        cin>>cenx[i]>>ceny[i]>>r[i];
    i++;
    }
int count=0;
while(cin>>x>>y)
    {
    int fig=0,sign=0;
    count++;
    if(x==9999.9&&y==9999.9)
        break;
    while(flag[j]!='*')
        {
        fig++;
        if(flag[j]=='r')
            if(x>a[j]&&x<c[j]&&y<b[j]&&y>d[j])
                {
                cout<<"Point "<<count<<" is contained in figure "<<fig<<endl;
                sign=1;
                }
        if(flag[j]=='c')
            if(((cenx[j]-x)*(cenx[j]-x)+(ceny[j]-y)*(ceny[j]-y))<r[j]*r[j])
                {
                cout<<"Point "<<count<<" is contained in figure "<<fig<<endl;
                sign=1;
                }
        j++;
        }
    if(sign==0)
        cout<<"Point "<<count<<" is not contained in any figure"<<endl;
    j=0; sign=0;
    }
return 0;
}
