#include<stdio.h>
#include<string.h>
int main(){
char src[100];
char dest[8];
printf("enter input not more than 8:");
fgets(src,sizeof(src),stdin);
src[strcspn(src,"\n")]='\0';
if (strlen(src)<sizeof(dest)){
strcpy(dest,src);
printf("Copied: %s\n",dest);
}else {
printf("Error: Input too long!\n ");
}
return 0;
}

