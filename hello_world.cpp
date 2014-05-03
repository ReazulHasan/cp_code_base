#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;

int fact(int x){
    int coun = 0;
    while(x%2==0 && x>=2){
        coun++;
        x/=2;
        if(coun>=2)
            return 1;
    }
    return 0;
}

int main()
{
   int m,n,i,j;
   map<int,int> mp;
   for(i=2; i<=500; i*=2)
        mp[i] = 1;
   while(cin>>m>>n){
        if(m==0 && n==0)
            break;
        if(m==1)
            cout<<n;
        else if(n==1)
            cout<<m;
        else if(m==2 && n==2)
            cout<<"4";
        else if((m==2 && fact(n)))
            cout<<n;
        else if(n==2 && fact(m))
            cout<<m;
        else if(m==2)
            cout<<(n/2)*2+2;
        else if(n==2)
            cout<<(m/2)*2+2;
        else{
            if((m*n)%2)
                cout<<(m*n)/2+1;
            else
                cout<<(m*n)/2;
        }
    cout<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<endl;
   }
}
