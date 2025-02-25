# Exercise 4.1 gebruik van function pointers

## function pointer
Definitie van een function pointer is in basis:

*typefunction (* function)(type arg1, type arg2)*

## model functie pointer in dit programma
De functies die gebruikt gaat worden in de functie pointer zijn:
*int sum(int num1, int num2);*
*int sub(int num1, int num2);*
*int mult(int num1, int num2);*
*int divd(int num1, int num2);*

Dus het model is: **int (* ope)(int, int)**	// * ope is de pointer naar de functie

nu kan *operations[n].ope* een pointer naar een functie bevatten:
**operations[0].ope = sum;**           // ope krijgt pointer naar sum

