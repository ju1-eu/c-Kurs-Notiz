/* 
	ju 6-Mrz-20 VergleichsOperator.c
	Hinweis: debuggen
*/
#include <stdio.h>
int main(){
  int a = 22;
  int b = 42;
  int comp;

  comp = (a > b);
  comp = (a < b);
  comp = (a == b);
  comp = (a <= b);
  comp = (a >= b);
  comp = (a != b);
  
  //printf("Comp: %d\n", comp);

  return 0;
}