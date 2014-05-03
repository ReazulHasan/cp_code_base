#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int n,flag[10][10],coun=0,res=0;
string bord[10];

int recur(int x,int y)
{
int i,j,k;
flag[x][y]=1;
//cout<<"coun: "<<coun<<", x: "<<x<<", y: "<<y<<endl;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(bord[i][j]=='.'&&flag[i][j]==0)
            {
            int ro=-1,co=-1,tmp;
            for(k=0;k<n;k++)
                {
                if(flag[i][k]==1)
                    co=k;
                if(flag[k][j]==1)
                    ro=k;
                }
            if(ro==-1&&co==-1)
                {
                coun++;
                recur(i,j);
                coun--;
                }
            else
                {
                int m=i,n=j,p,q,ok1=0,ok2=0;
                if(co>=0&&co<n)
                    {
                    tmp=co;
                    co=n;
                    n=tmp;
                    }
                if(ro>=0&&ro<m)
                    {
                    tmp=ro;
                    ro=m;
                    m=tmp;
                    }
                if(co>=0)
                for(p=n;p<=co;p++)
                    if(bord[i][p]=='X')
                        ok1=1;
                if(ro>=0)
                for(p=m;p<=ro;p++)
                    if(bord[p][j]=='X')
                        ok2=1;
                if(ro<0)
                    ok2=1;
                if(co<0)
                    ok1=1;
                if(ok1&&ok2)
                    {
                    coun++;
                    recur(i,j);
                    coun--;
                    }
                }
            }
if(res<coun)
    res=coun;
}

int main()
{
int i,j,k,p,q;
while(cin>>n&&n)
    {
    res=0;
    for(i=0;i<n;i++)
        cin>>bord[i];
    /*for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            cout<<bord[i][j];
        cout<<endl;
        }*/
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(bord[i][j]=='.')
                {
                for(p=0;p<n;p++)
                    for(q=0;q<n;q++)
                        flag[p][q]=0;
                coun=1;
                recur(i,j);
                }
    cout<<res<<endl;
    }
return 0;
}
