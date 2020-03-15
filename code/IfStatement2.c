/* 
	ju 6-Mrz-20 IfStatement2.c
	
  && (Konjunktion), logical AND operator
  || (Disjunktion), logical OR operator
  !  (Negation),    logical NOT operator
*/
#include <stdio.h>
int main(){
  int age_jan = 16;
  int age_marc = 16;
  int age_sarah = 16;

  // wer ist der juengste?
  if ((age_jan < age_marc) && (age_jan < age_sarah)){
    printf("Jan ist der juengste!");
  }
  else if ((age_marc < age_jan) && (age_marc < age_sarah)){
    printf("Marc ist der juengste!");
  }
  else if ((age_sarah < age_jan) && (age_sarah < age_marc)){
    printf("Sarah ist der juengste!");
  }
  else{  
    if ((age_jan == age_sarah) && (age_jan == age_marc)){
      printf("3 Personen sind gleich alt!");
    }
    else{
      printf("2 Personen sind gleich alt!");
    }
  }

  return 0;
}