#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 50;
int main(){
char buffer[MAX_LEN];
char *name;
printf("enter name");
fgets(buffer,sizeof(buffer),stdin);
buffer[strcspn(buffer,"\n")] = '\0';
name = (char *)malloc(strlen(buffer) + 1);
if (name == NULL) {
printf("memory allocation failed\n");
return 1;
}
strcpy(name, buffer);
printf("hello %s\n",name);
free(name);
return 0;
}

