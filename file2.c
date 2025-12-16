#include<stdio.h>
#include"file1.c"
extern int shared_global_variable;

int main(){
access_shared_global();
getch();
return 0;
}

