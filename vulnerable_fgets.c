#include<stdio.h>
int main(){
char buf[10];
printf("inter input to display:");
fgets(buf,100,stdin);
printf("you entered: %s\n",buf);
return 0;
}

