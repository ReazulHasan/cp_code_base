#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int i,j, arr[10];

for (i = 1; i <= argc; i++)
{
printf("\n input:%s integer(output):%d",argv[i],atoi(argv[i]));
if (i < 10)
arr[i-1] = atoi(argv[i]);
}

for (j = 0; j < i; j++)
if (j < 10)
printf("\n arr[%d]: %d", j, arr[j]);


return 0;
}