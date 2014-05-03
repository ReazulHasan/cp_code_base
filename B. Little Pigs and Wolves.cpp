#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#define pi 2*acos(0.0)
#define siz 1000000
typedef long long ll;
typedef double dd;
int prime[siz+5],isp[siz+5],in;
using namespace std;
char ar[100][100];
char data[100][100];
int m,n;




int main(){
    char faltu[10];
    while(cin>>m>>n){
        gets(faltu);
        for(int i=0;i<m;i++){
        gets(ar[i]);
        }int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ar[i][j]=='P'){
                    if(i+1<m){
                    if(ar[i+1][j]=='W'){
                        cnt++;
                        ar[i][j]='a';
                        ar[i+1][j]='b';

                    }
                    }
                }
                if(ar[i][j]=='P'){
                    if(i-1>0){
                    if(ar[i-1][j]=='W'){
                        cnt++;
                        ar[i][j]='a';
                        ar[i-1][j]='b';

                    }
                    }
                }
                if(ar[i][j]=='P'){
                    if(j+1<n){
                    if(ar[i][j+1]=='W'){
                        cnt++;
                        ar[i][j]='a';
                        ar[i][j+1]='b';

                    }
                    }
                }if(ar[i][j]=='P'){
                    if(j-1>0){
                    if(ar[i][j-1]=='W'){
                        cnt++;
                        ar[i][j]='a';
                        ar[i][j-1]='b';

                    }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }




    return 0;
}
