#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define p 1000


int main()
{
    char a[10000],b[10000],c[10000];
    ///a and b are the two arrays for input values and c is the array for resulting value
    int i,n,j,k,l,m;
    while(scanf("%s%s",&a,&b)==2)
    {
        int la=strlen(a),lb=strlen(b);
        if(la<lb)
        {
            strrev(a);
            for(i=la;i<lb;i++)
            a[i]='0';
            strrev(a);
        }
        else            ///if(la==lb) then the for loop will stop just after starting
                        ///you can also write else if(la>lb), same statement
        {
            strrev(b);
            for(i=lb;i<la;i++)
            b[i]='0';
            strrev(b);
        }
        l=strlen(a);

        ///remember la and lb are the sizes before the if-else part so anyone of them can be changed :)
        ///coz if la<lb we are inserting 0's to a, so strlen(a) is not la now :)
        ///but after inserting 0's strlen(a) = strlen(b) now :)

        int rem=0,index=0;

        ///rem is a variable that keep tracks of the remainder and index is the index of the resulting array

        for(i=l-1;i>=0;i--)
        {
            n=a[i]-'0'+b[i]-'0'+rem; /// two digits from the arrays and if there is any earlier remainder, rem then add it
            rem=n/10;   /// rem = the remainder
            m=n%10;     /// m = the ultimate digit we are going to insert into resulting array, c;
            c[index++]=m+'0'; /// we are inserting m into c
        }

        if(rem>0)   ///that means I have some remainder in hand, so add that :)
        c[index++]=rem+'0';
        strrev(c);
        //cout<<c<<endl;
        printf("%s\n",c);

        ///clearing the resulting array c
        for(i=0;i<index;i++)
        c[i]='\0';
    }
    return 0;
}
