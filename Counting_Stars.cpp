#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
char a[109][109];
int r,c,i,j,k;
while(cin>>r>>c&&r&&c)
    {
    int coun=0;
    for(i=0;i<r;i++)
        cin>>a[i];
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            {
            int flag=0;
            if(a[i][j]=='*')
                {
                if(i>0&&j>0)
                    if(a[i-1][j-1]=='*')
                        flag=1;
                if(i>0)
                    if(a[i-1][j]=='*')
                    flag=1;
                if(i>0&&j<(c-1))
                    if(a[i-1][j+1]=='*')
                        flag=1;
                if(j>0)
                    if(a[i][j-1]=='*')
                    flag=1;
                if(j<(c-1))
                    if(a[i][j+1]=='*')
                        flag=1;
                if(i<(r-1)&&j>0)
                    if(a[i+1][j-1]=='*')
                        flag=1;
                if(i<(r-1))
                    if(a[i+1][j]=='*')
                        flag=1;
                if(i<(r-1)&&j<(c-1))
                    if(a[i+1][j+1]=='*')
                        flag=1;
                }
        if(a[i][j]=='*'&&flag==0)
            coun++;
            }
        }
    cout<<coun<<endl;
    }
return 0;
}
