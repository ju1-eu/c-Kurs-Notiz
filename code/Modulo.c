/* 
	ju 6-Mrz-20 Modulo.c
	
*/
#include <stdio.h>
int main(){
  int a = 110;
  int b = 8;

  int div_result = a / b;
  int div_rest = a % b;

  printf("A / B = %d\n", div_result);
  printf("A %% B = %d\n", div_rest);

  return 0;
}