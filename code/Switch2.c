/* 
	ju 6-Mrz-20 Switch2.c
	Getraenkeautomat: 4x Gedraenke (Tasten)
*/
#include <stdio.h>
#define cola   0
#define icetea 1
#define water  2
#define coffee 3
int main(){
  int selection;
  printf("Bitte ein Gedraenk auswaehlen!\n");
  scanf("%d", &selection);

  switch(selection){
    case cola: printf("Cola!\n"); break;
    case icetea: printf("IceTea!\n"); break;
    case water: printf("Water!\n"); break;
    case coffee: printf("Coffee!\n"); break;
    default: printf("unbekannte Nummer! Eingabe: 0 bis 3");
  }

  return 0;
}