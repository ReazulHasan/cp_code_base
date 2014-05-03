#include <stdio.h>
#include<string.h>
int main()
{
    int i,j,n,len,item1,item2,res,rem=0,index=0,k;
    char a[150],b[150];
    for(i=0;i<150;i++)
        {
        a[i]='\0';
        b[i]='\0';
        }
    scanf("%d %s",&n,&a);
    for(i=0;i<n;i++)
        {
        j=0; len=strlen(a);
        while(j<len)
            {
            item1=a[j++]-'0'+rem*10;
            while(item1<n)
                {
                item2=item1*10+a[j++]-'0';
                item1=item2;
                }
            res=item1/n;
            b[index++]=res+'0';
            rem=item1%n;
            res=0; item1=0;
            }
        for(k=0;k<strlen(b);k++)
            a[k]=b[k];
            index=0; res=0; item1=0; rem=0;
        }
    printf("%s\n",a);
    return 0;
}
