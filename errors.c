#include<stdio.h>
int main()
 {
 int my_num=8; //function scope
 int your_num=10;
 { // inner block of code
 int new_num=20; // block scope
 int my_num=30;
 your_num=30;
 }
 printf(“ new_num =%d\n ”, new_num); // output …. ?
 printf(“ my_num= %d \n ”, my_num); // output …. ?
 printf(“ yuor_num= %d \n ”, your_num); // output …. ?
return 0;
}