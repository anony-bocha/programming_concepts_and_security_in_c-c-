#include<stdio.h>

int main(){
int my_num=8;
int your_num=10;
{
int new_num=20;
int my_num=30;
your_num =30;//modifies the outer one
}
//printf("new_num=%d\n",new_num);//compile time error because it is declared in the inner
printf("my_num=%d\n ",my_num);//this is shadowing so the out put is the first global it self=8
printf("your_num=%d\n",your_num);//the inner modifies the outer so the output is 30
return 0;

}