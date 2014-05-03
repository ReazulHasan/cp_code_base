#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
char c;
int x,a[100],k=0,i;
while(cin>>i)
{
int m,n;
cin>>m>>n;
int lo=min(m,n);
cout<<lo<<endl;
cin>>x;
while(((c=getchar())!='\n'))
    {
    cin>>x;
    a[k++]=x;
    //cout<<c<<x<<"hmm";
    }
for(i=0;i<k;i++)
    cout<<a[i]<<" ";
}
return 0;
}
