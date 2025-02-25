# Exercise 2.2 call by value and using dereferencing
Kern van deze opdracht is het gebruik van call by value

**void average2D(double *pD1, double *pD2);**

**average2D(*&*d1, *&*d2);**

## call by reference 
Bij deze functie worden d1 en d2 middels **pointers** als **call by reference** naar de functie gestuurd.

Dit geeft de mogelijkheid om de waarden van d1 en d2 middels **dereferencing** te manipuleren:

waarde ophalen: result = (**\***pD1 + **\***pD2)/2;
waarde wijzigen: **\***pD1 = result;

## referencing en dereferencing

Gegeven een pointer:  int *pVar = &eeninteger;

### dereferencing
*\*pVar* is dan een dereference voor de pointer, of te wel de inhoud van het geheugen waar deze pointer naar verwijst

### referencing
*&eeninteger* is de reference naar een variabel, of te wel het adres waar deze variabele is opgeslagen.