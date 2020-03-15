/*
  ju 6-Mrz-20 Printf-Wertebereich-Fehler.c
  printf
  d or i	Signed  integer
  u	    Unsigned integer
  char =  8bit = 1byte, 2^8  = 256
  int  = 32bit = 4byte, 2^32 = 4.294.967.296
*/
#include <stdio.h>
int main(){
  // -128, 127
  char c_value_f = 200; // falsch
  char c_value = 127;   // korrekt
  // 0, 255
  unsigned char uc_value_f = 300;// falsch
  unsigned char uc_value = 200;  // korrekt
  // 0, 4.294.967.295
  unsigned int ui_value_f = -26; // falsch
  unsigned int ui_value = 1000;  // korrekt

  printf("%i\n", c_value_f); 
  printf("%i\n", c_value); 
  printf("%u\n", uc_value_f);
  printf("%u\n", uc_value);
  printf("%u\n", ui_value_f);
  printf("%u\n", ui_value);
  return 0;
}