/* 
	ju 6-Mrz-20 IfStatement4.c
	Kurzschreibweisen
  if (Ausdruck) wahr; 
  else falsch;
  (Ausdruck) ? wahr : falsch;
*/
#include <stdio.h>
int main(){
  int age_jan = 16;

  if ((age_jan % 2) == 0) printf("Jan's age is gerade!\n");
  else printf("Jan's age is ungerade!\n");


  ((age_jan % 2) == 0) ? printf("Jan's age is gerade!\n") : printf("Jan's age is ungerade!\n");

  return 0;
}