/* 
	ju 6-Mrz-20 programmieruebung2.c
	Programmierübung:
	1. if-else-Abfrage, prüfe ob eine ganze Zahl durch 3 teilbar ist
	2. Beide Fälle ausgeben.
	3. Den Modulo Rest ausgeben

	a % 3 == 0
*/
#include <stdio.h>
int main(){
	unsigned int number = 0;

	printf("Bitte eine ganze zahl eingeben!\n");
	scanf("%d", &number);

  unsigned int mod_rest = (number % 3);
  
	if(mod_rest == 0)
		printf("Number ist durch 3 teilbar!\n");
	else{
    printf("Number ist nicht durch 3 teilbar!\n");
    printf("Modulo-Rest: %d\n", mod_rest);
  }

  return 0;
}

