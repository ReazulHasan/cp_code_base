#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
int a[1000],b,c,i,j,k,x,y;
while(cin>>x)
    {
    a[0]=x;
    //cout<<a[0]<<endl;
    for(i=1;i<9;i++)
        cin>>a[i];
    int pow=8,flag=0;
    for(i=0;i<8;i++)
        {
        if(a[i]!=0)
            {
            if(a[i]<0)
                {
                int nw=a[i];
                nw*=-1;
                if(flag==0)
                    cout<<"-";
                else
                    cout<<" - ";
                if(a[i]==-1)
                    cout<<"x";
                else if(a[i]<-1)
                    cout<<nw<<"x";
                if(pow>1)
                    cout<<"^"<<pow;
                }
            else
                {
                if(flag==1)
                    cout<<" + ";
                if(a[i]==1)
                    cout<<"x";
                if(a[i]>1)
                    cout<<a[i]<<"x";
                if(pow>1)
                    cout<<"^"<<pow;
                }
            flag=1;
            a[i]=0;
            }
        a[i]=0;
        pow--;
        }
    if(a[8]<0)
        {
        int nw=a[8];
        nw*=-1;
        if(flag==0)
            cout<<"-";
        else
            cout<<" - ";
        cout<<nw;
        flag=1;
        a[8]=0;
        }
    else if(a[8]>0)
        {
        if(flag==0)
            cout<<a[8];
        else
            cout<<" + "<<a[8];
        flag=1;
        a[8]=0;
        }
    if(flag==0)
        cout<<"0"<<endl;
    if(flag==1)
        cout<<endl;
    for(i=0;i<10;i++)
        a[i]=0;
    }
return 0;
}
