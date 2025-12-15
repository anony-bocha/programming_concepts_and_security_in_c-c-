#include<stdio.h>
int main(){
int arr[5] = {10,20,30,40,50};
int *p = arr;
printf("arr[0] address= %d\n",arr);
printf("arr[0] value= %d\n",*p);
printf("arr[1]= %d\n",*(p+1));
printf("arr[2]=%d\n",*(p+2));
return 0;
}

