# Zeiger (Pointer) und Adressen

<!--7-Mrz-20-->

- `Adressoperator &` = Adresse einer Variablen
- `* -Operator` = Zeiger deklarieren, der auf eine Variable zeigt
- `Dereferenzierungs-Operator *` = Inhalt einer Speicherstelle

```
    int var;        // Name einer Variablen steht stellvertretend
                        für den Inhalt der Speicherstelle
    &var;           // Adresse der Integervariablen
    int* iptrVar;   // Interger-Pointer wird deklariert
    iptrVar = &var; // Pointer wird eine Adresse zugewiesen
    *iptrVar = 20;  // Speicherstelle, auf die der Pointer zeigt,
                        wird ein wert zugewiesen
```
