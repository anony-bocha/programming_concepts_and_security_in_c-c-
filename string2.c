#include<stdio.h>
int main(){
char name[10];
printf("enter your name:");
fgets(name,sizeof(name),stdin);
printf("hello %s",name);

return 0;
}

