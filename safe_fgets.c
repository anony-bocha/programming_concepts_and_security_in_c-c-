#include<stdio.h>
int main(){
char buf[10];

printf("enter the input:");
fgets(buf,sizeof(buf),stdin);
printf("you entered:%s\n",buf);
return 0;
}

