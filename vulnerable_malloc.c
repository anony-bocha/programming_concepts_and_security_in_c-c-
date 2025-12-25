#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *name;

name = (char *)malloc(5);
printf("enter name:");
fgets(name,100,stdin);

printf("Hello %s\n",name);
free(name);
return 0;
}

