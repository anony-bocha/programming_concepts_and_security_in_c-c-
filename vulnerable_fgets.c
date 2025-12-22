#include<stdio.h>

int main(){
char buf[8];
printf("enter input:");
fgets(buf,100,stdin);
printf("you entered: %s\n,buf");
return 0;
}

