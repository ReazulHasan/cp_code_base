//Merge Sort

#include<stdio.h>

int a[15],i,j,num,temp[15],pos=0;

void conquer(int start,int mid,int end){
    int x=start,y=mid+1,z=end;
    pos=start;
    while(x<=mid && y<=z){
        if(a[x]<a[y])
            temp[pos++]=a[x++];
        else if(a[y]<a[x])
            temp[pos++]=a[y++];
        else{
            temp[pos++]=a[x++];
            temp[pos++]=a[y++];
        }
    }
    while(x<=mid)
        temp[pos++]=a[x++];
    while(y<=z)
        temp[pos++]=a[y++];

}

void divide(int start,int end){
    int mid=(start+end)/2;
    if(start<end){
        divide(start,mid);
        divide(mid+1,end);
    }
    printf("start: %d, mid: %d, end: %d\n",start,mid,end);
    conquer(start,mid,end);
}

int main()
{
    scanf("%d",&num);
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);

    divide(0,num);

    for(i=0;i<num;i++)
        printf(" %d",temp[i]);

    return 0;
}
