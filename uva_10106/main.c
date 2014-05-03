#include <stdio.h>
int main()
{
int index=0,i,j,res=0,car=0,count1=0,count2=0,x=0,y=0;
char a[300],b[300],c[300],d[300],e[300],f[300];
for(i=0;i<300;i++)
    {
        a[i]='\0';
        b[i]='\0';
        c[i]='\0';
        d[i]='\0';
        e[i]='\0';
        f[i]='\0';
    }
        scanf("%s%s",&a,&b);
        for(i=0;a[i]!='\0';i++)
            count1++;
        for(i=0;b[i]!='\0';i++)
            count2++;
        int flag1=count2-1,flag2=0;
        for(j=0;j<count2;j++)
            {
                flag2++;
                for(i=count1-1;i>=0;i--)
                {
                    res=((a[i]-'0')*(b[flag1]-'0'))+car;
                    c[index++]=res%10+'0';
                    car=res/10;
                }
                x=0;
                for(i=0;c[i]!='\0';i++)
                    x++;
                if(flag2==1)
                    {
                    for(i=0;i<x;i++)
                        d[i]=c[i];
                    }
                else
                    {
                    y=0;
                    for(i=0;d[i]!='\0';i++)
                        y++;
                    if(y>x)
                        {
                        c[y-1]='0';
                        }
                    else if(x==y)
                        {
                        index=0;
                        c[x]='0';
                        for(i=x-1;i>=0;i--)
                            e[index++]=d[i];
                        e[x]='0';
                        index=0;
                        for(i=x;i>=0;i--)
                            d[index++]=e[i];
                        }
                    else
                        {
                        d[x]='0';
                        index=0;
                        for(i=y-1;i>=0;i--)
                            e[index++]=c[i];
                        for(i=y;i<=x;i++)
                            e[i]='0';
                        index=0;
                        for(i=x;i>=0;i--)
                            c[index++]=e[i];
                        }
                    int z=0;
                    for(i=0;c[i]!='\0';i++)
                        z++;
                    flag2=0;
                    res=0; car=0;
                    for(i=z-1;i>=0;i--)
                        {
                        res=c[i]-'0'+d[i]-'0'+car;
                        f[flag2++]=res%10+'0';
                        car=res/10;
                        }
                    for(i=0;i<z;i++)
                        d[i]=f[i];
                    }
                flag1--;
            }
    printf("result is %s\n",d);
    return 0;
}
