#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
int t,i,j=0,res[100],k=0;
double det,x[100],y[100];
double x1,y1,x2,y2,x3,y3,x4,y4,a1,b1,c1,a2,b2,c2;
cin>>t;
for(i=1;i<=t;i++)
    {
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    a1=y2-y1;
    b1=x1-x2;
    c1=a1*x1+b1*y1;
    a2=y4-y3;
    b2=x3-x4;
    c2=a2*x3+b2*y3;
    det=a1*b2-a2*b1;
    if(det==0)
        {
        if((a1*x3+b1*y3)==c1)
            res[j++]=-1;
        else
            res[j++]=0;
        }
    else
        {
        x[k]=((b2*c1)-(b1*c2))/det;
        y[k]=(c2*a1-c1*a2)/det;
        res[j++]=1;
        k++;
        }
    }
k=0;
cout<<"INTERSECTING LINES OUTPUT"<<endl;
for(i=0;i<t;i++)
    {
    if(res[i]==-1)
        cout<<"LINE"<<endl;
    if(res[i]==0)
        cout<<"NONE"<<endl;
    if(res[i]==1)
        {
            printf("POINT %.2lf %.2lf\n",x[k],y[k]);
        k++;
        }
    }
cout<<"END OF OUTPUT"<<endl;
return 0;
}
