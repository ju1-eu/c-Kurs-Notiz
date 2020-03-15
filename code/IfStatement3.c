/* 
	ju 6-Mrz-20 IfStatement3.c
	Welches alter ist durch 2 teilbar?
  teilbar bzw. gerade zahl: a % 2 == 0
*/
#include <stdio.h>
int main(){
  int age_jan = 16;
  int age_marc = 17;
  int age_sarah = 18;

  if ((age_jan % 2) == 0){
    printf("Jan's age is gerade!\n");
  }
  else{
    printf("Jan's age is ungerade!\n");
  }

  if ((age_marc % 2) == 0){
    printf("Marc's age is gerade!\n");
  }
  else{
    printf("Marc's age is ungerade!\n");
  }

  if ((age_sarah % 2) == 0){
    printf("Sarah's age is gerade!\n");
  }
  else{
    printf("Sarah's age is ungerade!\n");
  }

  return 0;
}