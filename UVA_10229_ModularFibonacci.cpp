#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int[2][2] matrix_mult(int[][] x,int[][] y,int m){
    int,i,j,k;
    int res[2][2];
    for(i=0;i<2;i++)
        for(j=0;j<2;j++){
            int sum = 0;
            for(k=0;k<2;k++)
                sum += (x[i][k]%m) * (y[k][j]%m);
            res[i][j] = sum%m;
        }
    return res;
}


int[2][2] matrix_pow(int[2][2] mat,n,m){
    if(n==0){
        int x[2][2];
        x[0][0]=1; x[0][1]=0;
        x[1][0]=0; x[1][1]=1;
        return x;
    }
    else if(n%2==0){
        int[2][2] x = matrix_pow(mat,n/2,m);
        return matrix_mult(x,x,m);
    }
    else if(n%2){
        int[2][2] x = matrix_pow(mat,n-1,m);
        return matrix_mult(mat,x,m);
    }
}

int main(){
int mat[2][2],temp[2][2];
int i,j,k,n,m;
while(cin>>n>>m){

    if(n==0) break;

    mat[0][0]=1; mat[0][1]=1;
    mat[1][0]=1; mat[1][1]=0;
    double mod = pow(2.0,m);

    matrix_pow(mat,n,m);
    //cout<<mod<<endl;
}
return 0;
}
