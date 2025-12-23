#include<stdio.h>
#include<string.h>
int main(){
char dest[8];
char src[]="cyber";
strncpy(dest,src,sizeof(dest)-1);
dest[sizeof(dest) -1] = '\0';
printf("copied string:%s\n",dest);
return 0;
}

