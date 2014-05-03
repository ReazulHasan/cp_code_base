//Quick Sort

#include<stdio.h>

int a[15],i,j;

void quick_sort(int start,int end){
    int x=start,y=end;
    int mid = (start+end)/2;
    printf("start: %d,mid: %d,end: %d\n",start,mid,end);
    while(x<y){
        while(a[x]<a[mid])
            x++;
        while(a[y]>a[mid])
            y--;
        if(x<=y){
            int temp=a[x];
            a[x]=a[y];
            a[y]=temp;
            x++; y--;
        }
    }
    if(x<end)
        quick_sort(x,end);
    if(y>start)
        quick_sort(start,y);
}

int main(){
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    quick_sort(0,9);

    for(i=0;i<10;i++)
        printf(" %d",a[i]);
    printf("\n");
}
