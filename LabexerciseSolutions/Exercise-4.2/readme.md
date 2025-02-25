# Exercise 4.2 Callback functie i.c.m. qsort()
## Functie qsort() om een reeks van gegevens te sorteren
Het model voor de functie die kan sorteren (qsort()) is:void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))

## function pointer die vergelijking maakt
Hierin zit de pointer naar een functie die twee elementen van de reeks vergelijkt:

**int (*compar)(const void *, const void*)**

In de code wordt dan de functie gemaakt die deze vergelijking uitvoert en past bij het gevraagde model:

**int compareZipcode(const void *pZC1, const void *pZC2)**

Deze functie vergelijkt twee element van de struct zipcode_t met als resultaat:

|Resultaat|Conditie               |
|---------|-----------------------|
|-1       |ZC1 is kleiner dan ZC2 |
|+1       |ZC1 is groter dan ZC2  |
|0        |ZC1 is gelijk aan ZC2  |

## basis compareZipcode()

Vergelijking op nummer, als de nummers gelijk zijn wordt er vergeleken op letters met strcmp()
