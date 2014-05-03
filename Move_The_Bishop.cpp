#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int main()
{
long long i,j,k,pox,poy,jax,jay,cas,n,difx,dify,m;
cin>>cas;
while(cas--)
    {
    cin>>n>>m;
    while(n--)
        {
        cin>>pox>>poy>>jax>>jay;
        if(pox>m||poy>m||jax>m||jay>m||pox<1||poy<1||jax<1||jay<1)
            cout<<"no move"<<endl;
        else
            {
            if(pox>jax)
                difx=pox-jax;
            else
                difx=jax-pox;
            if(poy>jay)
                dify=poy-jay;
            else
                dify=jay-poy;
            if(pox==jax&&poy==jay)
                cout<<"0"<<endl;
            else if((difx%2)!=(dify%2))
                cout<<"no move"<<endl;
            else
                {
                if(difx==dify)
                    cout<<"1"<<endl;
                else
                    cout<<"2"<<endl;
                }
            }
        }
    }
return 0;
}
