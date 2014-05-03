#include<math.h>
#include<iostream>
using namespace std;
int main()
{
   long double f,s,t;
   //freopen("in.txt","r",stdin);
   while(scanf("%lf%lf",&f,&s)==2)
   {
      t=exp(log(s)/f);
      printf("%.0lf\n",t);
   }
return 0;
}
