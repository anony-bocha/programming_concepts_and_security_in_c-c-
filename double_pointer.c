#include<stdio.h>
int main(){
int x = 100;
int *p =&x;
int **pp = &p;

printf("value of x: %d\n",x);
printf("using *p: %d\n",*p);
printf("using **pp: %d\n",**pp);
return 0;
}

