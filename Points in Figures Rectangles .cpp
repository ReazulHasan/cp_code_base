#include<iostream>
using namespace std;

main()
{
    double x[15],y[15],x1[15],y1[15],dis,a,b,res;
    int i,j,k,l,n,p;
    char like;
    i=0;
    while(cin>>like)
    {
        if(like=='*')
        break;

        cin>>x[i]>>y[i]>>x1[i]>>y1[i];
        i++;
    }
    k=p=0;
    while(cin>>a>>b)
    {
        k=0;
        if(a==9999.9&&b==9999.9)
        break;
        p++;
        for(j=0;j<i;j++)
        {
            if((a>x[j]&&a<x1[j])&&(b<y[j])&&(b>y1[j]))
            {
                k=1;
                printf("Point %d is contained in figure %d\n",p,j+1);
            }
        }
        if(k==0)
        printf("Point %d is not contained in any figure\n",p);
    }
    return 0;
}
