# Dezimal - Binär - Hexadezimal

<!--7-Mrz-20-->

| **DEZ** | **HEX** | **BIN** |
| :------ | :------ | :------ |
| 0       | 0       | 0000    |
| 1       | 1       | 0001    |
| 2       | 2       | 0010    |
| 3       | 3       | 0011    |
| 4       | 4       | 0100    |
| 5       | 5       | 0101    |
| 6       | 6       | 0110    |
| 7       | 7       | 0111    |
| 8       | 8       | 1000    |
| 9       | 9       | 1001    |
| 10      | A       | 1010    |
| 11      | B       | 1011    |
| 12      | C       | 1100    |
| 13      | D       | 1101    |
| 14      | E       | 1110    |
| 15      | F       | 1111    |

## Beispiel

| \#  | **8** | **7** | **6** | **5** | **4** | **3** | **2** | **1** |
| :-- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |
| n   | 7     | 6     | 5     | 4     | 3     | 2     | 1     | 0     |
| 2^n | 128   | 64    | 32    | 16    | 8     | 4     | 2     | 1     |
| bin | 1     | 0     | 1     | 1     | 0     | 0     | 0     | 0     |
| hex |       |       |       | B     |       |       |       | 0     |

## Wahrheitstabelle

| **E1** | **E2** | **UND** | **ODER** | **XOR** | **NEG** | **NAND** | **NOR** |
| :----- | :----- | :------ | :------- | :------ | :------ | :------- | :------ |
| 0      | 0      | 0       | 0        | 0       | 1       | 1        | 1       |
| 0      | 1      | 0       | 1        | 1       | 1       | 1        | 0       |
| 1      | 0      | 0       | 1        | 1       | 0       | 1        | 0       |
| 1      | 1      | 1       | 1        | 0       | 0       | 0        | 0       |

## Datentypen

| **Typ**            | **Bit** | **Wertebereich** |         **\#** |
| :----------------- | ------: | ---------------: | -------------: |
| char               |       8 |       -128 … 127 |     -2^… 2^7-1 |
| unsigned char      |       8 |          0 … 255 |      0 … 2^8-1 |
| int                |      16 |   -32768 … 32767 | -2^15 … 2^15-1 |
| unsigned int       |      16 |        0 … 65535 |     0 … 2^16-1 |
| long               |      32 |                  | -2^31 … 2^31-1 |
| unsigned long      |      32 |                  |     0 … 2^32-1 |
| long long          |      64 |                  | -2^63 … 2^63-1 |
| unsigned long long |      64 |                  |     0 … 2^64-1 |