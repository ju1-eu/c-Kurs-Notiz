/*
  ju 6-Mrz-20 programmieruebung.c
  Programmierübung 1:
  1. Alter des Benutzers
  2. Berechne wie viele Tage, Stunden, Minuten, Sekunden er bereits lebt.
  3. Hinweis: akt. Datum als festen Wert in Variable speichern.
*/
#include <stdio.h>
int main(){
  //int geb_datum = 20.4.1975;
  //int akt_datum =  6.3.2020;
  unsigned char alter = 0;
  unsigned int tage = 16392; // https://www.umrechnung.org/exaktes-alter/wie-alt-bin-ich-genau.htm
  unsigned int tage_berechnet = 0;
  unsigned int stunden = 0;
  unsigned int minuten = 0;
  unsigned int sekunden = 0;

  printf("Bitte geben Sie ihr Alter ein!\n");
  scanf("%d", &alter);// 44

  tage_berechnet = alter * 365; // Hinweis: ohne Schaltjahr
  stunden = tage * 24;
  minuten = stunden * 60;
  sekunden = minuten * 60;

  return 0;
}