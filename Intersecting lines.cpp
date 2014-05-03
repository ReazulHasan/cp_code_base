#include<iostream>
using namespace std;

main()
{
    int i,n,j,k,l;
    double x[100],y[100],t,res[100],x1[100],y1[100];
    double det,a1,b1,c1,a2,b2,c2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=4;j++)
        {
            cin>>x[j]>>y[j];
        }
        a1=y[2]-y[1];
        b1=x[1]-x[2];
        c1=x[1]*a1+y[1]*b1;
        a2=y[4]-y[3];
        b2=x[3]-x[4];
        c2=x[3]*a2+y[3]*b2;
        double det=a1*b2-a2*b1;
        if(det==0){
            if((a2*x[1]+b2*y[1])==c2)
            res[i]=0;
            else
        res[i]=-1;
        }
        if(det!=0)
        {
            x1[i]=(b2*c1-b1*c2)/det;
            y1[i]=(a1*c2-a2*c1)/det;
            res[i]=1;
        }

    }
cout<<"INTERSECTING LINES OUTPUT\n";
    for(i=0;i<n;i++)
    {

        if(res[i]==0)
        cout<<"LINE"<<endl;
        else if(res[i]==-1)
        cout<<"NONE"<<endl;
        else
        printf("POINT %.2lf %.2lf\n",x1[i],y1[i]);
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
