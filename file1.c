#include<stdio.h>



void access_shared_global(){
printf("value of shared_global_variable from file2:%d\n",shared_global_variable);
}
int main(){
int shared_global_variable=50;
return 0;
}

