# C - Komplettkurs

<!--7-Mrz-20-->

## Variablen und Datentypen

### Zahlen als Variable

- Int = Ganze Zahl
- Unsigned Int = Natürliche Zahl
- Float = "Reelle Zahl" / "Rationale Zahl"
- Double = "Reelle Zahl" / "Rationale Zahl"

`int number2 = -1337; // Deklaration + Initialisierung`

### Rechenoperationen

    // Multiplikation: *
    c = a * b; // = 25.0
    // Division: /
    c = (a / b) * 5; // = 5.0
    // Adition: +
    c = a + b; // = 10.0
    // Subtraktion: -
    c = a - b; // = 0.0
    // c^2 = a^2 + b^2
    c_squared = a*a + b*b;
    //b = b + 1;
    b += 1;

### Ausgabe in der Konsole

    int x = 1;
    double y = 2.0;
    unsigned int z = 3;
    float alpha = 4.0;

    printf("Der Inhalt von x ist: %d\n", x);
    printf("Der Inhalt von y ist: %lf\n", y);
    printf("Der Inhalt von z ist: %u\n", z);
    printf("Der Inhalt von alpha ist: %lf\n", alpha);

### Einlesen aus der Konsole

    printf("Wert fuer die Variable a eingeben!\n");
    scanf("%f", &a);
    printf("Wert fuer die Variable b eingeben!\n");
    scanf("%f", &b);

### Wertebereiche der Datentypen

    #include <limits.h>
    #include <float.h>
    long long j = 1;
    printf("Var j: %d\n", sizeof(j));
    printf("Ranges fuer Int: %d, %d\n", INT_MIN, INT_MAX);
    printf("Ranges fuer Float: %E, %E\n", FLT_MIN, FLT_MAX);

### Buchstaben als Variable

    char buchstabe_A = 'A';
    printf("Buchstabe: %d\n", buchstabe_A);
    printf("Buchstabe: %c\n", buchstabe_A);
    printf("Buchstabe: %x\n", buchstabe_A);

### Darstellung von Integer Zahlen

    int b_dezimal = 312; // 100111000
    int b_binaer = 0b100111000;
    int b_hex = 0x138;

    printf("Die Zahl in Dezimal: %d\n", b_dezimal);
    printf("Die Zahl in Binaer: 0b100111000\n");
    printf("Die Zahl in Hex: 0x%x\n", b_hex);

### Darstellung von Float Zahlen

    double a = 0.1;
    double b = 0.1;
    double c = a + b;

    printf("A: %.23f\n", a);
    printf("B: %.23f\n", b);
    printf("C: %.23f\n", c);
    printf("D: %.23f\n", 0.2);

### Programmierübung 1

1. Alter des Benutzers
2. Berechne wie viele Tage, Stunden, Minuten, Sekunden er bereits lebt.
3. Hinweis: akt. Datum als festen Wert in Variable speichern.

```
    unsigned char alter = 0;
    // https://www.umrechnung.org/exaktes-alter/wie-alt-bin-ich-genau.htm
    unsigned int tage = 16392; // Stand: 6.3.20
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
```

## Abfragen und Logik

### Modulo Operator

    int div_result = a / b;
    int div_rest = a % b;

### Vergleich Operatoren

    comp = (a > b);
    comp = (a < b);
    comp = (a == b);
    comp = (a <= b);
    comp = (a >= b);
    comp = (a != b);

### If Abfrage

    1 = true
    0 = false

    if (age_jan < age_marc){
    printf("Jan ist juenger als Marc!");
    }
    else if (age_jan > age_marc){
        printf("Jan ist älter als Marc!");
    }
    else{
        printf("Jan and Marc sind gleich alt!");
    }

### If Abfrage mit logischen Operatoren

    && (Konjunktion), logical AND operator
    || (Disjunktion), logical OR operator
    !  (Negation),    logical NOT operator

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

### If Abfrage mit Modulo

    Welches alter ist durch 2 teilbar?
    teilbar bzw. gerade zahl: a % 2 == 0

    if ((age_jan % 2) == 0){
    printf("Jan's age is gerade!\n");
    }
    else{
        printf("Jan's age is ungerade!\n");
    }

    if ((age_marc % 2) == 0){
        printf("Marc's age is gerade!\n");
    }
    else{
        printf("Marc's age is ungerade!\n");
    }

    if ((age_sarah % 2) == 0){
        printf("Sarah's age is gerade!\n");
    }
    else{
        printf("Sarah's age is ungerade!\n");
    }

### Verkürzte If Abfragen

    Kurzschreibweisen
    if (Ausdruck) wahr;
    else falsch;
    (Ausdruck) ? wahr : falsch;

### Switch Abfrage

    Getraenkeautomat: 4x Gedraenke (Tasten)

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

### Enum für die Switch Abfrage

    enum = Konstante Werte: cola = 0

    enum Drink {cola, icetea, water, coffee};

    int selection;
    printf("Pls enter a valid code for any drink!\n");
    scanf("%d", &selection);

    switch(selection){
        case cola: printf("Cola!\n"); break;
        case icetea: printf("IceTea!\n"); break;
        case water: printf("Water!\n"); break;
        case coffee: printf("Coffee!\n"); break;
        default: printf("You did not enter a valid number!");
    }

### Programmierübung 2

Programmierübung:

1. if-else-Abfrage, prüfe ob eine ganze Zahl durch 3 teilbar ist
2. Beide Fälle ausgeben.
3. Den Modulo Rest ausgeben

```
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
```

## Schleifen

### Inkrement und Dekrement

    IncDec.c

### While Schleife

    While.c

### While Sprunganweisungen

    While2.c

### Do-While Schleife

    While3.c

### Fertigstellung des Ratespiels

    GameNumberGuesser.c

### For Schleife

    For.c

### Verschachtelte For Schleife

    For2.c

### Programmierübung 3:

        ContentChapter4.c

## Funktionen und Header

### Funktions-Deklaration und Definition

    Functions.c

### Funktions Return Type

    Return.c

### Code auslagern in eine Header Datei

    FunctionsBib.c
    FunctionsBib.h

### Eine komplexere Funktion

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Externe Header verwenden

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Intuition: Rekursion

### Rekursive Funktionen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Gültigkeitsbereiche

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 4

        FunctionsBib.c
        FunctionsBib.h
        Main.c

## Einfache Zeiger

### Adresse und Inhalt einer Variable

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Zeiger erstellen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Intuition: Zeiger

### Call by Value vs. Call by Reference

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 5:

        FunctionsBib.h
        FunctionsBib.c
        Main.c

## Arrays

### Intuition: Arrays

### Eindimensionale Arrays

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Mehrdimensionale Arrays

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Die Größe eines Arrays bestimmen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Array als Funktions Parameter

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 6:

        FunctionsBib.c
        FunctionsBib.h
        Main.c

## Zeiger Arrays

### Stack vs. Heap

    Stack vs. Heap.pptx

### Malloc und Free

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Intuition: Pointer Arrays

### Zeiger Arrays Returnen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Mehrdimensionale Zeiger Arrays

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 7:

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### NULL und void Pointer

    Main.c

### Calloc und Realloc

        Main.c

## Strings

### Eindimensionale Strings

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Mehrdimensionale Strings

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### String Funktionen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 8:

        FunctionsBib.c
        FunctionsBib.h
        Main.c

## Strukturen und Typedef

### Structs erstellen

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Funktionen mit Structs

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Zeiger und Structs

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Typedef

    FunctionsBib.c
    FunctionsBib.h
    Main.c

### Programmierübung 9:

        FunctionsBib.c
        FunctionsBib.h
        Main.c

## Schreiben und Lesen von Dateien

### Lesen aus Dateien

    FunctionsBib.c
    FunctionsBib.h
    Main.c
    InputData.txt

### Schreiben in Dateien

    FunctionsBib.c
    FunctionsBib.h
    Main.c
    OutputData.txt

### Programmierübung 10:

        FunctionsBib.c
        FunctionsBib.h
        InputData.txt
        Main.c
        OutputData.txt

## Fortgeschrittene Techniken

### Defines und Const Werte

    Main.c

### Include Guards

    File.c
    FunctionsBib.h
    FunctionsBib.c
    Main.c

### Implizite und Explizite Typen-Umwandlung

    Main.c

### Complexe Zahlen

    Main.c

### Binäre Operatoren

    Main.c

### Clock() CPU-Zeit

    Main.c

### Time() und Timestamps

    Main.c

### Main Funktion: argc und argv

    Main.c

### Sortieren: Bubblesort

    Main.c

### Sortieren: Quicksort

    Main.1.c

### Programmierübung 11:

        Main.c
        Data.txt

## Programmierprojekt

Programmierprojekt zum Abschluss des Kurses

### Create und Delete Vector

    1 - Create and Delete.zip
    Start Code.zip

### Rechnungen mit dem Vector

    2 - Math Functions.zip

### Dateiverarbeitung mit dem Vector

        3 - Files.zip
