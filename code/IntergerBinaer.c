// ju 6-Mrz-20 IntegerBinaer.c
#include <stdio.h>
int main(){
  int b_dezimal = 312; // 100111000
  int b_binaer = 0b100111000;
  int b_hex = 0x138;

  printf("Die Zahl in Dezimal: %d\n", b_dezimal);
  printf("Die Zahl in Binaer: 0b100111000\n");
  printf("Die Zahl in Hex: 0x%x\n", b_hex);

  return 0;
}