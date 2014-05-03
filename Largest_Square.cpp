#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main()
{
char a[150][150],z[5];
int t,m,n,q,i,j,k;
cin>>t;
while(t--)
    {
    cin>>m>>n>>q;
    gets(z);
    for(i=0;i<m;i++)
        gets(a[i]);
    int r,c;
    cout<<m<<" "<<n<<" "<<q<<endl;
    while(q--)
        {
        cin>>r>>c;
        char it=a[r][c];
        int rolo=r,rohi=r,colo=c,cohi=c;
        int flag=0,coun=1;
        while(1)
            {
            rolo--; rohi++;
            colo--; cohi++;
            if(rolo<0||colo<0||rohi>=m||cohi>=n)
                break;
            for(i=rolo;i<=rohi;i++)
                {
                for(j=colo;j<=cohi;j++)
                    {
                    if(a[i][j]!=it)
                        {
                        flag=1;
                        break;
                        }
                    }
                if(flag==1)
                    break;
                }
            if(flag==1)
                break;
            if(flag==0)
                coun+=2;
            }
        cout<<coun<<endl;
        }
    }
return 0;
}
