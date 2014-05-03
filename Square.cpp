#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int t,n,a[100],i,j,k,flag[100];
cin>>t;
while(t--)
    {
    for(i=0;i<100;i++)
        {
        a[i]=0;
        flag[i]=0;
        }
    int peri=0,sid;
    cin>>n;
    for(i=0;i<n;i++)
        {
        int x;
        cin>>x;
        a[i]=x;
        peri+=x;
        }
    sort(a,a+n);
    if(peri%4!=0)
        cout<<"no"<<endl;
    else
        {
        sid=peri/4;
        if(a[n-1]>sid)
            cout<<"no"<<endl;
        else
            {
            int coun=0;
            for(i=n-1;i>=0;i--)
                {
                if(flag[i]==0)
                    {
                    flag[i]=1;
                    int it=sid-a[i];
                    if(it>0)
                        {
                        for(j=i-1;j>=0;j--)
                            {
                            if(a[j]<=it&&flag[j]==0)
                                {
                                flag[j]=1;
                                it-=a[j];
                                if(it==0)
                                    break;
                                }
                            }
                        }
                    if(it!=0)
                        {
                        cout<<"no"<<endl;
                        break;
                        }
                    else
                        coun++;
                    }
                }
            if(coun==4)
                cout<<"yes"<<endl;
            }
        }
    }
return 0;
}
