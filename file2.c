#include<stdio.h>
#include"file1.c"
extern int shared_global_variable;
void access_shared_global(){
printf("value of shared_global_variable from file2:%d\n",shared_global_variable);
}
int main(){
access_shared_global();
getch();
return 0;
}

