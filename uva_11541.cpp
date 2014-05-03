#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    char ch,a[500],c,item;
    int n,i,j,freq=0,k,b;
    cin>>n;
    //cin>>c;
    for(i=1;i<=n;i++)
        {
         gets(a);
         int len=strlen(a);
         printf("%s",a);
         printf("%d",len);
         cout<<len;
         cout<<"Case"<<" "<<i<<":"<<" ";
         j=0;
         while(j<len)
            {
                if(a[j]>='A'&&a[j]<='Z')
                    {
                    item=a[j];
                    j++;
                    }
                int m=0;
                while((a[j]<'A'||a[j]>'Z')&&j<len)
                    {
                        freq=a[j]-'0';
                        b=m*10+freq;
                        m=b;
                        j++;
                    }
                for(k=1;k<=m;k++)
                    cout<<item;
            }
        cout<<endl;
        }
    return 0;
}
