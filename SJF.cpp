#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
using namespace std;

struct ss{
int burst,arr,proc,flag;
};

int main()
{

int i,j,k,num,b,a,p;
ss t;
ss fuki[10009];
cout<<"Please Enter the Total Number of Processes: ";
cin>>num;
cout<<"Please Enter the Process Number, Burst Time & Arrival Time consequently: "<<endl;
for(i=1;i<=num;i++)
    {
    cin>>p>>b>>a;
    t.proc=p;
    t.burst=b;
    t.arr=a;
    t.flag=0;
    fuki[i]=t;
    }
int x=0,y=0;
cout<<"The output is in the format ( Start-Procss_No-Finish)"<<endl;
int aslo=0,en=0,coun=0,dela=0;
while(1)
    {
    int minarr=98769876,minburst=98769875;
    coun++;
    int process,hm;
    if(coun==1)
        {
        for(i=1;i<=num;i++)
            if(minarr>fuki[i].arr&&fuki[i].flag==0)
                {
                minarr=fuki[i].arr;
                process=fuki[i].proc;
                }
        for(i=1;i<=num;i++)
            if(minarr==fuki[i].arr&&fuki[i].flag==0)
                if(minburst>fuki[i].burst)
                    {
                    minburst=fuki[i].burst;
                    process=fuki[i].proc;
                    }
        dela=minarr+minburst;
        hm=dela;
        cout<<"( "<<minarr<<"-P"<<process<<"-"<<dela<<" )";
        }
    else
        {
        cout<<" | ";
        for(i=1;i<=num;i++)
            {
            if(fuki[i].arr<=dela&&fuki[i].flag==0)
                if(minburst>fuki[i].burst)
                    {
                    minburst=fuki[i].burst;
                    process=fuki[i].proc;
                    }
            }
        dela+=minburst;
        cout<<"( "<<hm<<"-P"<<process<<"-"<<dela<<" )";
        hm=dela;
        }

    for(i=1;i<=num;i++)
        if(fuki[i].proc==process)
                {
                fuki[i].flag=1;
                break;
                }
    if(coun==num)
        {
        cout<<endl;
        break;
        }
    }

}
