#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int cost[500][500];
int inf=9876549;
int imf=98888889;

int main()
{
int i,j,k,pep,road,x,y,c,cas=0;
while(cin>>pep>>road&&pep)
    {
    cas++;
    map<string,int> mpstr;
    map<int,string> mpint;
    string s;
    k=1;
    for(i=1;i<=pep;i++)
        {
        cin>>s;
        mpstr[s]=k;
        mpint[k]=s;
        k++;
        }
    for(i=1;i<=pep;i++)
        for(j=1;j<=pep;j++)
            {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=inf;
            }
    for(i=1;i<=road;i++)
        {
        cin>>x>>y>>c;
        cost[x][y]=c;
        cost[y][x]=c;
        }
    /*for(i=1;i<=pep;i++)
        {
        cout<<i<<endl;
        for(j=1;j<=pep;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
        }*/
    for(k=1;k<=pep;k++)
        for(i=1;i<=pep;i++)
            for(j=1;j<=pep;j++)
                if(cost[i][j]>(cost[i][k]+cost[k][j]))
                    cost[i][j]=cost[i][k]+cost[k][j];
    int min=imf,no;
    for(i=1;i<=pep;i++)
        {
        int sum=0;
        for(j=1;j<=pep;j++)
            {
            sum+=cost[i][j];
            //cout<<cost[i][j]<<" ";
            }
        //cout<<endl;
        //cout<<"min sum "<<min<<" "<<sum<<endl;
        if(min>sum)
            {
            //cout<<"hi"<<endl;
            min=sum;
            no=i;
            }
        }
    cout<<"Case #"<<cas<<" : "<<mpint[no]<<endl;
    mpint.clear(); mpstr.clear(); s.clear();
    }
return 0;
}
