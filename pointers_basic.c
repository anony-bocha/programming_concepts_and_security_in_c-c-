#include<stdio.h>
int main(){
int age =27;
int *ptr;
ptr=&age;
printf("value of age:%d\n",age);
printf("address of age: %p\n",&age);
printf("pointer value(address):%p\n",ptr);
printf("value using pointer: %d\n",*ptr);
return 0;
}

