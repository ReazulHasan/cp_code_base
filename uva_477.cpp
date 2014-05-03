#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
double a[400],x1,y1;
int i=0,j=0,index1=0,fig=0,flag=0,count=0;
char c;
cin>>c;
while(c!='*')
    {
    if(c=='r')
        cin>>a[index1++]>>a[index1++]>>a[index1++]>>a[index1++];
    else if(c=='c')
        {
            a[index1++]=' ';
            cin>>a[index1++]>>a[index1++]>>a[index1++];
        }
    cin>>c;
    }

while(cin>>x1>>y1)
    {
    if(x1==9999.9&&y1==9999.9)
        break;
    i=0; j=0;
    count++;
    while(i<index1)
        {
        fig++;
        if(a[i]==' ')
            {
                if(((a[i+1]-x1)*(a[i+1]-x1)+(a[i+2]-y1)*(a[i+2]-y1))<a[i+3]*a[i+3])
                    {
                    cout<<"Point "<<count<<" is contained in figure "<<fig<<endl;
                    flag=1;
                    }
            }
        else if(x1>a[i]&&x1<a[i+2]&&y1<a[i+1]&&y1>a[i+3])
            {
            flag=1;
            cout<<"Point "<<count<<" is contained in figure "<<fig<<endl;
            }
        i+=4;
        }
    if(flag==0)
        cout<<"Point "<<count<<" is not contained in any figure"<<endl;
        flag=0; fig=0;
    }
return 0;
}
