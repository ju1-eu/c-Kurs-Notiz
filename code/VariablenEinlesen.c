// ju 6-Mrz-20 VariablenEinlesen.c
#include <stdio.h>
int main(){
  float a;
  float b;
  float c;
  int x;
  int y;
  int z;

  printf("Wert fuer die Variable a eingeben!\n");
  scanf("%f", &a);
  printf("Wert fuer die Variable b eingeben!\n");
  scanf("%f", &b);

  c = a * b;
  printf("C = A * B = %f\n", c);

  printf("Wert fuer die Variable x eingeben!\n");
  scanf("%d", &x);
  printf("Wert fuer die Variable y eingeben!\n");
  scanf("%d", &y);

  z = x * y;
  printf("Z = X * Y = %d\n", z);

  return 0;
}