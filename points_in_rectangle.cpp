#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
float a[50],b[50],x,y;
char c;
int i,j,count1=0,count2=0,k,m;
for(i=0;i<50;i+=4)
    {
    cin>>c;
    if(c=='*') break;
    else
        {
        count1+=4;
        j=i;
        cin>>a[j++]>>a[j++]>>a[j++]>>a[j++];
        }
    }
    for(i=0;i<50;i+=2)
    {
        count2+=2;
        j=i;
        cin>>b[j]>>b[++j];
        if(b[j]==9999.9&&b[j+1]==9999.9)
            break;
    }
    i=0;
    for(i=0;i<count2;i++)
        {
        j=i;
        if(b[j]==9999.9&&b[j+1]==9999.9)
            break;
        else
            {
                x=b[j++]; y=b[j++];
                for(k=0;k<count1;k+=4)
                    {
                      m=k;
                      if(x>a[m]&&x<a[m+2]&&y>a[m+1]&&y<a[m+3])

                    }
            }
        }
}
