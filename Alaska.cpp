#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int a[2000],i,j,n;
while(cin>>n&&n)
    {
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if((1422-a[n-1])>100)
        cout<<"IMPOSSIBLE"<<endl;
    else
        {
        int flag=0;
        for(i=1;i<n;i++)
            if((a[i]-a[i-1])>200)
                {
                flag=1;
                cout<<"IMPOSSIBLE"<<endl;
                break;
                }
        if(flag==0)
            cout<<"POSSIBLE"<<endl;
        }
    }
return 0;
}
