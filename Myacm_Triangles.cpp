#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

double area(double x1,double y1,double x2,double y2,double x3,double y3)
{
return (x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1);
}

int main()
{
int i,j,k,n;
double a[1000],b[1000];
double x1,y1,x2,y2,x3,y3;
while(cin>>n&&n)
    {
    char ch;
    for(i=0;i<n;i++)
        cin>>ch>>a[i]>>b[i];
    double hi=0.0;
    string s;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=j+1;k<n;k++)
                {
                x1=a[i]; y1=b[i];
                x2=a[j]; y2=b[j];
                x3=a[k]; y3=b[k];
                //double tri=(x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1);
                double tri=area(x1,y1,x2,y2,x3,y3);
                if(tri<0)
                    tri*=-1;
                if(hi<tri)
                    {
                    int flag=0;
                    for(int m=0;m<n;m++)
                        if(m!=i&&m!=j&&m!=k)
                            {
                            double x4,y4;
                            x4=a[m]; y4=b[m];
                            double tri1,tri2,tri3;
                            tri1=area(x1,y1,x4,y4,x2,y2);
                            if(tri1<0)
                                tri1*=-1;
                            tri2=area(x2,y2,x4,y4,x3,y3);
                            if(tri2<0)
                                tri2*=-1;
                            tri3=area(x1,y1,x4,y4,x3,y3);
                            if(tri3<0)
                                tri3*=-1;
                            if(tri==(tri1+tri2+tri3))
                                {
                                flag=1;
                                break;
                                }
                            }
                    if(flag==0)
                        {
                        s.clear();
                        hi=tri;
                        ch='A'+i; s+=ch;
                        ch='A'+j; s+=ch;
                        ch='A'+k; s+=ch;
                        }
                    }
                }
    cout<<s<<endl;
    }
return 0;
}
