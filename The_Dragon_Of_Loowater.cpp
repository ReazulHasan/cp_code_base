#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
int gos,nit,i,j,k,go[40000],ni[40000];
while(cin>>gos>>nit)
    {
    if(gos==0&&nit==0)
        break;
    for(i=0;i<gos;i++)
        cin>>go[i];
    for(i=0;i<nit;i++)
        cin>>ni[i];
    if(nit<gos)
        {
        cout<<"Loowater is doomed!"<<endl;
        continue;
        }
    sort(go,go+gos);
    sort(ni,ni+nit);
    int coun=0,cost=0;
    for(i=0;i<nit;i++)
        {
        int x=ni[i];
        if(x!=-1)
        for(j=gos-1;j>=0;j--)
            {
            if(go[j]!=-1)
                if(go[j]<=x)
                    {
                    coun++;
                    cost+=x;
                    ni[i]=-1;
                    go[j]=-1;
                    break;
                    }
            }
        }
    if(coun==gos)
        cout<<cost<<endl;
    else
        cout<<"Loowater is doomed!"<<endl;
    }
return 0;
}
