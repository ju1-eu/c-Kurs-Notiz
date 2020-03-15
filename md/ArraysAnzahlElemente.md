# Elementanzahl bei Arrays ermitteln

<!--7-Mrz-20-->

Wir haben hier ein Byte-Array mit 10 Elementen. Wenn wir dieses Array
iterieren wollen könnten wir das in einer for-Schleife tun:

    byte bArray[10];
    for ( int i = 0; i < 10; i++ ){
        tueWasMit(bArray[i]);
    }

Das würde auch so funktionieren. Dumm nur, wenn wir sehr viele dieser
Schleifen haben und das Array sehr häufig zum Einsatz kommt. Wenn wir
nämlich jetzt die Anzahl erhöhen oder verringern, müssen wir das an
allen Stellen tun und das ist mehr als aufwendig und fehleranfällig.
Aber wir kennen ja schon unsere `#define` Direktive.

Also legen wir ganz am Anfang einmal die Größe des Arrays fest und
können sie hier auch zentral ändern. Der Einsatz sähe dann wie folgt
aus:

    #define ARRAY_LAENGE 10
    byte bArray[ARRAY_LAENGE];
    for ( int i = 0; i < ARRAY_LAENGE; i++ ){
        tueWasMit(bArray[i]);
    }

Falls wir sehr viele Arrays haben, brauchen wir allerdings eine ganze
Menge `#defines`. Damit können wir zwar in den meisten Fällen gut leben,
aber es geht noch ein wenig eleganter und zwar mit `sizeof()`. Doch
dabei muss man wissen, was wirklich passiert.

    byte bArray[10];
    for ( int i = 0; sizeof(bArray); i++){
        tueWasMit(bArray[i]);
    }

Sie finden diese Konstruktion in sehr vielen Tutorials und
Dokumentationen und häufig wird auch ganz allgemein erwähnt, das
sizeof() die Anzahl der Elemente eines Arrays ermittelt. Das ist
allerdings so nicht richtig. Im vorliegenden Fall klappt es problemlos.
Warum? Weil wir ein Byte-Array haben. Schauen wir uns aber einmal die
Ausgabe an, wenn wir ein Integer-Array erzeugen.

Probieren Sie es doch einmal in Ihrer Arduino-IDE aus: Erzeugen Sie die
beiden Arrays:

    byte bArray[10];
    int iArray[10];

und lassen Sie die Größe mit sizeof() über die serielle Schnittstelle
ausgeben:

    byte bArray[10];
    int iArray[10];
    void setup(){
        Serial.begin(9600);
        Serial.print("Anzahl der Elemente (bArray): ");
        Serial.println(sizeof(bArray));
        Serial.print("Anzahl der Elemente (iArray): ");
        Serial.println(sizeof(iArray));
    }
    void loop(){

    }

Das Ergebnis sieht dann so aus:

    Anzahl der Elemente (bArray): 10
    Anzahl der Elemente (iArray): 20

Sizeof() ermittelt also nicht die Anzahl der Elemente, sondern schlicht
den Speicherbedarf und das sind bei Integer eben 20 Byte. ABER:

Ich führe das gleiche Programm mal mit einem MKRZERO durch. Hier muss
ich aber noch etwas ändern. Bei vielen älteren Arduino-Controllern führt
der Aufbau einer seriellen Verbindung zu einem Reset. Das ist beim
MKRZERO nicht mehr der Fall. Führe ich also einen Serial.print() Befehl
in der setup-Funktion aus, wird dieser nicht angezeigt, weil der Aufruf
des Serial-Monitors zu spät kommt. Deshalb füge ich hier hinter dem
Serial.begin() noch einen delay-Befehl mit 5 s ein. Nach dem Drücken der
Reset-Taste habe ich dann genug Zeit, den seriellen Monitor aufzurufen.
Es gibt auch noch eine andere Lösung, die ich im Abschnitt über die
Arduino IDE beschreibe. Das Ergebnis:

Nun, der MKRZERO ist ein 32-Bit-System und in einem solchen sind Integer
4 Byte lang, deshalb ermittelt sizeof() jetzt 40 Byte.

Doch wie kann ich sizeof() trotzdem für die Ermittlung der Elemente
nutzen? Das funktioniert mit folgendem Konstrukt:

    sizeof(iArray)/sizeof(iArray[0])

Was tun wir damit? Wir dividieren den Gesamtspeicher in Byte durch die
Größe eines Elementes und erhalten damit die Anzahl.

Besonders komfortabel wird es, wenn wir ein Makro nutzen:

    #define ELEMENT_COUNT(x)  (sizeof(x)/sizeof(x[0]))

Im Programm sähe das dann so aus:

    #define ELEMENT_COUNT(x)  (sizeof(x)/sizeof(x[0]))
    byte bArray[10];
    int iArray[10];
    void setup(){
        Serial.begin(9600);
        Serial.print("Anzahl der Elemente (bArray): ");
        Serial.println(ELEMENT_COUNT(bArray));
        Serial.print("Anzahl der Elemente (iArray): ");
        Serial.println(ELEMENT_COUNT(iArray));
    }
    void loop(){

    }

und das Ergebnis:

    Anzahl der Elemente (bArray): 10
    Anzahl der Elemente (iArray): 10
