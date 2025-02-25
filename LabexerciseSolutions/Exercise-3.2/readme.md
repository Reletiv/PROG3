# Exercise 3.2 Checking integers

## conditie + en - aan het begin
Controle van integers als onderdeel van de functie isInt() die in exercise 3.1 wordt gebruikt.
Teken van de integer testen, extra eis:

Een integer kan beginnen met + of -, dus dan mag het eerste karakter van de string (str[0]) een '+' of een '–' zijn. **str[0] == '+' || str[0] == '-'**
Een integer kan beginnen met een cijfer, dus dan mag het eerste karakter van de string (str[0]) een cijfer **isdigit(str[0])**

Dus check conditie is: 
**!(str[i] == '-' || str[i] == '+' || isdigit(str[i])**
Extra test is de controle of de string niet 0 lang is:
**str[0] == '\0'**

## aanpassing om break te vermijden

Breaks in een lus zijn op zich mogelijk, maar kunnen wel de begrijpelijke flow van het programma (voornamelijk bij aanpassingen code) vervelend beinvloeden.
In deze code is de break verwijderd door de conditie isInteger == true in de conditie voor de while loop op te nemen. Nu test de *while* of de loop beeindigd moet worden en vind er geen *break out of the loop* plaats.
