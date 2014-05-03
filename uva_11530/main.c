#include <stdio.h>
#include <string.h>
int main()
{
    char a[150],m;
    int x,i,n,j,sum=0,len,flag=0;
    for(i=0;i<150;i++)
        a[i]='\0';
    scanf("%d",&n);
    scanf("%c",&m);
    for(i=1;i<=n;i++)
        {
        gets(a);
        len=strlen(a);
        for(j=0;j<len;j++)
            {
            if(a[j]=='p'||a[j]=='t'||a[j]=='w')
                sum+=1;
            else if(a[j]=='q'||a[j]=='u'||a[j]=='x')
                sum+=2;
            else if(a[j]=='y'||a[j]=='v'||a[j]=='r')
                sum+=3;
            else if(a[j]=='s'||a[j]=='z')
                sum+=4;
            else if(a[j]==' ')
                sum+=1;
            else
                {
                x=(a[j]-'0'-'0')%3;
                if(x==0) sum+=3;
                else sum+=x;
                }
            }
        if(flag==n)
        printf("Case #%d: %d",i,sum);
        else printf("Case #%d: %d\n",i,sum);
        flag++;
        sum=0;
        for(j=0;j<len;j++)
            a[j]='\0';
            len=0;
        }
    return 0;
}
