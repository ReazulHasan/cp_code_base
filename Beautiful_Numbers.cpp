#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;

struct ss{
int fast,last,step;
};

int bas,lim,coun=1,res=0;

queue<ss> q;

/*int recur(int x)
{
int i,j,k;
ss t;
if(coun>=lim)
    {
    if(x>0)
        res+=2;
    else res++;
    }
if(x>0)
    {
    coun++;
    return recur(x-1);
    }
else
    {
    coun++;
    return recur(x+1);
    }
}*/

int main()
{
int i,j,k,cas;
ss t,d;
cin>>cas;
while(cas--)
    {
    coun=1;
    res=0;
    cin>>bas>>lim;
    t.fast=bas-1;
    t.last=0;
    t.step=bas;
    q.push(t);
    while(!q.empty())
        {
        t=q.front();
        int prothom=t.fast,ses=t.last,bar=t.step;
        if(bar>lim)
            break;
        q.pop();
        if(prothom>1)
            {
            d.fast=prothom-1;
            d.last=ses;
            d.step=bar+1;
            res++;
            q.push(d);
            if(prothom<bas-2)
                {
                d.fast=prothom+1;
                res++;
                q.push(d);
                }
            }
        if(ses>0)
            {
            d.last=ses-1;
            d.fast=prothom;
            d.step=bar+1;
            res++;
            q.push(d);
            if(ses<bas-2)
                {
                d.last=ses+1;
                res++;
                q.push(d);
                d.fast=ses+1;
                d.last=prothom;
                res++;
                q.push(d);
                }
            if(ses-1>0)
                {
                d.fast=ses-1;
                d.last=prothom;
                res++;
                q.push(d);
                }
            }
        if(ses==0)
            {
            d.fast=prothom;
            d.last=ses+1;
            d.step=bar+1;
            res++;
            q.push(d);
            d.fast=ses+1;
            d.last=prothom;
            res++;
            q.push(d);
            }
        }
    cout<<res<<endl;
    }
return 0;
}
