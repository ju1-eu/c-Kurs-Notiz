/* 
	ju 6-Mrz-20 IfStatement.c
	1 = true
  0 = false
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
  int age_jan = 24;
  int age_marc = 42;

  if (age_jan < age_marc){
    printf("Jan ist juenger als Marc!");
  }
  else if (age_jan > age_marc){
    printf("Jan ist älter als Marc!");
  }  
  else{
    printf("Jan and Marc sind gleich alt!");
  }

  return 0;
}