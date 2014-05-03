#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define max 100

int main()
{
int graph[max][max],cost[max],prev[max],used[max],i,j,k,ver,edg,v1,v2;
cin>>ver>>edg;
for(i=0;i<edg;i++)
    {
    cin>>v1>>v2;
    cin>>graph[v1][v2];
    }
}
