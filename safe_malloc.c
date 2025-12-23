#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *ptr;
char msg[]="yonatan";
ptr=(char *)malloc(strlen(msg)+1);
strcpy(ptr,msg);
printf("%s\n",ptr);
free(ptr);
return 0;
}

