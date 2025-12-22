#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *ptr;
 ptr = (char *)malloc(5);
 strcpy(ptr,"cyberSecurity");
 printf("%s\n",ptr);
 free(ptr);
 return 0;
 }

