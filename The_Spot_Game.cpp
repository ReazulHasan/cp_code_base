#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

char bord[105][55][55],ch,now[55][55];
int m,n;

int check()
{
int i,j,k;
for(i=0;i<m;i++)
    {
    int fl=1;
    for(j=0;j<n;j++)
        {
        for(k=0;k<n;k++)
            {
            if(bord[i][j][k]!=bord[m][j][k])
                {
                fl=0;
                break;
                }
            }
        if(fl==0)
            break;
        }
    if(fl)
        return 1;
    }
return 0;
}

int check_again()
{
int i,j,k;
for(i=0;i<m;i++)
    {
    int fl=1;
    for(j=0;j<n;j++)
        {
        for(k=0;k<n;k++)
            {
            if(bord[i][j][k]!=now[j][k])
                {
                fl=0;
                break;
                }
            }
        if(fl==0)
            break;
        }
    if(fl)
        return 1;
    }
return 0;
}

int main()
{
int i,j,k,x,y;
while(cin>>n&&n)
    {
    int coun=0,step=-1,win=-1;
    //for(i=0;i<=2*n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                bord[0][j][k]=' ';
    int p,q,r,s,ja=1;
    for(m=1;m<=2*n;m++)
        {
        coun++;
        cin>>x>>y>>ch;
        //cout<<x<<" "<<y<<" "<<ch<<endl;
        if(m>0)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    bord[m][i][j]=bord[m-1][i][j];
        if(ch=='+')
            bord[m][x-1][y-1]='.';
        else
            bord[m][x-1][y-1]=' ';
        if(ja)
            {
            p=check();
            //90 right
            int ro=0,co=0;
            for(i=n-1;i>=0;i--)
                {
                ro=0;
                for(j=0;j<n;j++)
                    {
                    now[(ro++)%n][co%n]=bord[m][i][j];
                    }
                co++;
                }
            q=check_again();
            ro=0;co=0;
            //90 left
            ro=0,co=0;
            for(i=0;i<n;i++)
                {
                ro=0;
                for(j=n-1;j>=0;j--)
                    now[ro++][co]=bord[m][i][j];
                co++;
                }
            r=check_again();
            //180
            ro=0;
            for(i=n-1;i>=0;i--)
                {
                co=0;
                for(j=n-1;j>=0;j--)
                    now[ro][co++]=bord[m][i][j];
                ro++;
                }
            s=check_again();
            //cout<<"coun: "<<coun<<" ,p: "<<p<<" ,q: "<<q<<" ,r: "<<r<<" ,s: "<<s<<endl;
            if(p||q||r||s)
                {
                step=coun;
                if(coun%2)
                    win=2;
                else
                    win=1;
                ja=0;
                }
            }
        }
        if(ja)
            cout<<"Draw"<<endl;
        else
            cout<<"Player "<<win<<" wins on move "<<step<<endl;
    }
return 0;
}
