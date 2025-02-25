# Exercise 2.3  Array's als argument

**void averageDdata(double data[], int size)**

## Array's als functie argument
Het overdragen van een array als functie argument gebeurt altijd als reference. Daarbij is de naam van de array de referentie naar de pointer voor de array. Referencing met een **&** is niet nodig.
## Gebruik van int size
Bij een array als functie argument is het **altijd noodzakelijk** om de **grootte** van de array mee te geven in de argumenten. De functie krijgt de array mee als reference en kan de grootte van de array niet bepalen.
## Gebruik array element in de functie.
In de oplossing staan twee mogelijkheden.

**void averageDdata(double data[], int size)**

Maakt gebruik van de index van de array

**void averageDdataPoint(double data[], int size)** 

Maakt gebruik van een pointer naar de array. Bij een pointer naar de array moet er dereferencing gebruikt worden.

   **sum = sum + *(pData+i);**

Let op waar de haakjes staan, eerst de pointer met i verhogen en dan de dereferencing gebruiken!