#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<queue>

using namespace std;

int main()
{
int i,j,k,man,lost,x,y,flag[100009],a,b;
while(cin>>man>>lost)
    {
    if(!man&&!lost)
        break;
    for(i=0;i<100001;i++)
        flag[i]=i;
    for(k=0;k<lost;k++)
        {
        cin>>x>>y;
        a=x; b=y;
        a=x-1;
        if(flag[a]!=a)
            {
            while(flag[a]!=a)
                {
                a=flag[a];
                a--;
                }
            //flag[a+1]=flag[y];
            }
       // else
            //flag[x]=flag[x];

        b=y+1;
        if(flag[b]!=b)
            {
            while(flag[b]!=b)
                {
                b=flag[b];
                b++;
                }
            //flag[b-1]=flag[x];
            }
        //else
            //flag[y]=flag[x];
        flag[a+1]=b-1;
        flag[b-1]=a+1;
        if(a==0)
            cout<<"* ";
        else
            cout<<flag[a-1]<<" ";
        if(b==man)
            cout<<"*"<<endl;
        else
            cout<<flag[b-1]<<endl;
        /*if(flag[y+1]!=y+1)
            {
            int m=flag[y+1];
            flag[m-1]=x;
            }
        else
            flag[y]=flag[x-1];*/
        }
    }
return 0;
}
