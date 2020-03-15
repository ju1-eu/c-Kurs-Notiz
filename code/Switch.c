/* 
	ju 6-Mrz-20 Switch.c
	Getraenkeautomat: 4x Gedraenke (Tasten)
*/
#include <stdio.h>
int main(){
  int cola = 0;
  int icetea = 1;
  int water = 2;
  int coffee = 3;

  int selection;
  printf("Bitte ein Gedraenk auswaehlen!\n");
  scanf("%d", &selection);

  switch(selection){
    case 0: printf("Cola!\n"); break;
    case 1: printf("IceTea!\n"); break;
    case 2: printf("Water!\n"); break;
    case 3: printf("Coffee!\n"); break;
    default: printf("unbekannte Nummer! Eingabe: 0 bis 3");
  }

  return 0;
}