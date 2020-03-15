# Variablen und Zeiger im Detail

<!--7-Mrz-20-->

Der Speicher eines Mikrocontrollers - oder Prozessors - ist in einzelne
Zellen aufgeteilt, die je nach Prozessorarchitektur z. B. 8, 16, 32 oder
64 bit groß sind (aktuell geläufige Größen).

"Beispiel Parkplatz" Auch hier
kann es Parkplätze für Busse, für Pkw und für Motorräder geben, die
unterschiedlich groß sind, um den Gesamtplatz besser zu nutzen.

Damit Sie Ihr Auto nachher auch wieder finden, hat jede Box eine Nummer,
also eine Adresse:

Sie können den Inhalt - das Auto - in dieser Adresse ändern, aber der
Platz bleibt immer an der gleichen Stelle.

Jetzt haben wir aus Effizienzgründen in unserem Parkhaus keine festen
Bereiche für Motorräder, Autos oder Busse bestimmt, sondern wir haben
den gesamten Platz in 1000 Boxen für Motorräder aufgeteilt. Kommt ein
Auto, bekommt es zwei Plätze zugewiesen, kommt ein Bus, sind es vier
Plätze.

Das könnte dann unseren Datentypen byte (Motorrad), int (Auto) und
double (Bus) entsprechen.

## Zuweisung

Jetzt wird auch deutlich, warum wir zunächst eine Variable deklarieren
müssen, denn damit legen wir die Größe fest, wir reservieren einen
freien Parkplatz für ein Motorrad, ein Auto oder einen Bus.

Würde wir ohne Deklaration schreiben:

    value = 100;

dann wüsste der Compiler gar nicht, welche "Parkplatzgröße" er nutzen
soll. Auf unser Parkhaus bezogen, könnte jetzt folgendes passieren:

Es kommt ein Bus und der stellt sich einfach in die freie Parkbox 739. Links und rechts stehen
aber schon jeweils zwei Motorräder. Der Bus braucht aber vier Parkplätze
und jetzt auch eine gute Haftpflichtversicherung.

Gehen wir davon aus, wir hätten alles richtig gemacht, nämlich die
Variable deklariert und dann einen Inhalt zugewiesen. Aber was genau
läuft bei einer Zuweisung denn wirklich im Hintergrund ab?

    byte value;
    value = 100;

Umgangssprachlich sagen wir:

Der Variablen "value" wird der Wert 100 zugewiesen. Aber was ist "value"
überhaupt? Der Controller kennt dieses Wort nicht, es dient
ausschließlich der besseren Verständlichtkeit beim Lesen des Quellcodes.
Der Begriff wird vom Compiler einfach als Adresse übersetzt. Hinter
"value" versteckt sich also nichts anderes als unsere Parkplatznummer.

Doch das scheint ja irgendwie auch nicht so ganz zu stimmen, denn wenn
wir z. B.:

    Serial.print(value);

ausführen lassen, erhalten wir ja den Inhalt und nicht die Adresse. Das
liegt aber einzig und allein daran, dass der Compiler das Ganze für sich
entsprechend interpretiert:

    value = 100;

interpretiert der Compiler als: schreibe eine 100 in die Speicherstelle
mit der Adresse "value".

Beim Serial.print() sieht es noch etwas ansders aus. Hieraus macht der
Compiler ein:

ich kopiere den Inhalt der Speicherstelle mit der Adresse "value" und
mache daraus eine lesbare Information, denn er erzeugt ja eine
Zeichenkette aus dem numerischen Wert.

## Adressen und Inhalte

Durch die obige Nutzung der Adresse in Form von "value = 100" kommt es
schnell zu Verwechselungen, denn wir sagen: "value ist gleich 100"... Auf
das Parkhaus übertragen wäre das so, als wenn uns jemand danach fragt,
was wir für ein Auto haben und wir würden sagen: 739... nur weil wir unser
Auto dort geparkt haben.

Es gibt aber auch Situationen, da müssen wir tatsächlich die Adresse
wissen. Wenn Sie in der Parkgarage Ihre Frau treffen und diese den Wagen
holen möchte, dann werden Sie Ihr nicht sagen: "es ist ein blauer Opel
Astra", sondern Sie werden Ihr sagen: "der Wagen steht in Box 739".

Wenn allerdings "value" die Adresse ist und bei allen Funktionen immer
deren Inhalt genutzt wird, wie kommen wir dann an die Adresse selbst?

Dazu gibt es den `Adressoperater &`, den wir einfach vor den
Variablennamen setzen. Doch so einfach können wir es uns nicht machen,
denn wenn wir jetzt versuchen mit:

    Serial.print(&value);

an die Adresse zu kommen, wird uns der Compiler einen Strich durch die
Rechnung machen und uns eine Fehlermeldung präsentieren. Serial.print()
erwartet als Wert nicht die Adresse, sondern nutzt eine Kopie des
Inhaltes von "value" wie oben erwähnt. Warum? Weil Serial.print() mit
dem Inhalt einiges anstellt, um ihn für die Ausgabe aufzubereiten. Der
Originalwert soll aber unverändert bleiben.

Eine derartige Übergabe einer Variablen an eine Funktion bzw. Methode,
nennt man "call by value". Der andere Fall, bei dem tatsächlich die
Adresse übergeben wird wäre "call by reference".

"call by value" im Parkhaus

Sie würden gern wissen, wir ihr blaues Auto mit roter Lackierung
aussähe. Dazu erstellen sie eine Kopie (wenn das mal so einfach ginge)
diese Kopie steht auf Parkplatz 790 und den Wagen fahren Sie dann ins
Schaufenster, damit Sie sich das Ganze anschauen können. Ihr Wagen
bleibt aber unangetastet.

"call by reference" im Parkhaus

Sie haben einen platten Reifen und rufen deshalb die Funktion
"Reifenwechsel" auf. Dieser Funktion übergeben Sie natürlich keine Kopie
Ihres Autos, denn es soll ja tatäschlich Ihr Auto repariert werden und
deshalb übermitteln Sie die Nummer des Parkplatzes.

Es gibt aber durchaus Funktionen, die Sie für die direkte Ausgabe der
Adresse nutzen können. Das funktioniert in C++ z. B. über "cout".

    #include <iostream>
    int main(){
    int iValue = 100;
    std::cout << "Adresse von iValue: " << &iValue << std::endl;
    return 0;
    }

Erzeugen Sie einen Datenstrom, der auf der Standardausgabe (cout) - das
ist das Konsolenfenster beim PC - ausgegeben wird. Der Strom besteht aus
der Zeichenkette gefolgt von der Adresse und abgeschlossen mit einer
End-Line-Sequenz.

Das Ergebnis sieht so aus:

    Adresse von iValue:

Ich habe das Programm als 32-Bit-Variante compiliert, deshalb ist die
Speicheradresse auch 32 Bit lang. Ich compiliere das Programm noch
einmal als 64-Bit-Ausführung und schaue mir das Ergebnis an:

    Adresse von iValue:

Die Adresse ist jetzt doppelt so lang. Übrigens wird sie bei jedem
Aufruf anders ausfallen, weil das Betriebssystem dem Programm natürlich
dynamisch einen Speicherbereich zuweist und der wird bei einem aktiven
System, in dem laufend Prozesse, Threads und Tasks gestartet und
gestoppt werden immer woanders liegen.

## Zeiger/Pointer und Adressen

Mit dem `Adressoperator &` können wir die Adresse einer beliebigen
Variable - und das können auch kompexeste Objekte sein - ermitteln. Doch
was tun wir, wenn wir eine solche Adresse irgendwo speichern möchten?
Zum Speichern brauchen wir eine Variable und die muss einen Datentypen
haben. Eine Adresse in einem 32-Bit-System ist immer 32 Bit lang, egal
auf welchen Datentyp sie zeigt. Doch wie gerade gesehen, stimmt das
Ganze nicht mehr, wenn ich das gleiche Programm für ein
64-Bit-Betriebssystem übersetze.

Aus diesem Grund gibt es Zeiger. Das sind spezielle Datentypen, mit
denen ich Adressvariablen definieren kann. Das folgende Programm zeigt
deren Einsatz:

    #include <iostream>
    int main(){
    int iValue = 100;
    int* iptrValue;
    iptrValue = &iValue;
    std::cout << "Adresse von iValue: " << iptrValue << std::endl;
    iptrValue++;
    std::cout << "Adresse von iValue: " << iptrValue << std::endl;
    return 0;
    }

Wir definieren mit dem `*-Operator`, dass es sich um einen Zeiger
handelt, der auf eine Integervariable zeigt. Warum ist es notwendig, das
der Datentyp angegeben wird, wenn alle Pointer doch die gleiche Länge
haben?

Das wird mit der Anweisung iptrValue++ deutlich, denn damit erhöhe ich
den Zeiger um einen Speicherplatz. Das Ergebnis:

    Adresse von iValue:
    Adresse von iValue:

Der Zeiger ist um vier Plätze weiter gesprungen, weil eine Integer beim
Microsoft C++-Compiler eben 4 Byte groß ist. Lassen wir das gleiche
Programm noch einmal durchlaufen und ändern den Datentyp von iValue auf
short und natürlich auch den Zeiger auf einen `short*`, dann kommt dieses
Ergebnis heraus:

    Adresse von iValue:
    Adresse von iValue:

Jetzt ist die Schrittweite nur noch 2 Byte, weil eine Variable vom Typ
"short" 2 Byte benötigt.

Jetzt fehlt nur noch eins: Was tun wir, wenn wir z. B. wissen wollen,
was sich nach dem Inkrementieren in unserer Speicherstelle befindet?

Dazu nutzen wir den `Dereferenzierungs-Operator *`, mit dem wir uns den
Inhalt einer Speicherstelle holen. Und das ist wirklich unschön gelöst
bei C bzw. C++, denn es ist der gleiche Operator, mit wir auch den
Zeiger deklarieren, obwohl beides nichts miteinander zu tun hat.

    #include <iostream>
    int main(){
    int iValue = 100;
    int* iptrValue;
    iptrValue = &iValue;
    std::cout << "Adresse von iValue: "   <<  iptrValue << std::endl;
    std::cout << "Inhalt von iptrValue: " << *iptrValue << std::endl;
    iptrValue++;
    std::cout << "Adresse von iValue: "   <<  iptrValue << std::endl;
    std::cout << "Inhalt von iptrValue: " << *iptrValue << std::endl;
    return 0;
    }

Ich habe das obige Programm jetzt um die Dereferenzierung erweitert und
gebe damit einmal den Inhalt der Speicherstelle aus, auf die "iptrValue"
zeigt und danach den Inhalt der nächsten Speicherstelle, die 2 Zellen
weiter beginnt.

    Adresse von iValue:
    Inhalt von iptrValue:
    Adresse von iValue:
    Inhalt von iptrValue:

Im ersten Fall ist es wie erwartet "100"... im zweiten Fall können wir gar
nichts erwarten, weil wir im Grunde auf eine beliebige Stelle im
Speicher zeigen und nachschauen, was sich dort befindet und das kann
alles sein.

Deshalb auch hier noch mal eine Warnung: Zeiger sind extrem mächtig,
weil es nichts gibt, das uns näher an die Hardware bringt und deshalb
liebe ich sie von ganzem Herzen. Aber es gibt kein besseres Werkzeug, um
sich sein Programm damit hoffnungslos zu zerschießen und deshalb habe
ich über kein Konstrukt öfter geflucht.

Deshalb diese vielleicht etwas trockene Exkursion und deshalb auch noch
ein Tipp zur Deklaration:

Dem Compiler ist es ist prinzipiell egal, in welchem Format Sie einen
Zeiger deklarieren:

    int *iPtr;
    int * iPtr;
    int* iPtr;

Sie werden auch alle Varianten in der Literatur finden. Ich persönlich
finde die letzten Form am aussagekräfigsten, denn es macht deutlich,
dass es sich um einen "Integerpointer" handelt und das die Variable nur
"iPtr" heißt. Und noch etwas: Benennen Sie Zeiger eindeutig, am besten
mit einem Präfix:

    iPtr... iptr... (Integer-Pointer)
    lPtr...lptr... (Long-Pointer)
    fPtr... fptr... (Float-Pointer)
    oPtr... optr... (allgemeine Objekt-Pointer)
