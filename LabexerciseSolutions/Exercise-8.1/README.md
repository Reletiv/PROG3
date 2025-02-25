# Review checkStrings assignment

See *bookcode/checkStrings* directory for sources.

# Exercise 8.1 Unit testing with Unity

Het gebruik van Unit vergt wel wat voorbereidend werk.

Bouw een teststructuur op:
/code/app	de applicaties/functies die getest moeten worden
/code/doc	de documentatie bij de functies
/code/test	de testscripts inclusief het Unity framework

Wat je in basis doet is de te testen functie uitvoeren met verschillende testcases. In opgave 7.2 is dat ook gebeurd, echter zonder raamwerk.
Het unity framework bidet de mogelijkheid om het testen van functie in te sluiten in een aantal macro's die het testen overzichtelijk maken.

## Over het testen in 7.2

In 7.2 is een tabel gemaakt met de verschillende test gevallen. In Unit doe je dat ook, maar er zijn macro's die helpen om het testen te structureren.

in 7.2. gebeurt het volgende:

```c
 a = true;
 b = false;
 c = false;
 result = false;
 if (testfunc(a, b, c) == result)
 {
    printf("%d passed\n", i);
 } else
 {
     printf("%d failed\n", i);
  }  
```

## vergelijk met een test in Unity

In unity kun je dat opnemen in een macro:

```c
a = true;
b = false;
c = false;
TEST_ASSERT_FALSE_MESSAGE(testfunc(a, b, c), "test 1");
```

Hier wordt dus getest of het resultaat van de testfunc() false is, als dat het  geval is dan is er een PASS anders is er een FAIL.

In de voorbeeldcode gebeurt dit in gestructueerder blokken code zodat de test duidelijk is.

Samengevat: met Unity kun je dus de testgevallen gestructureerd in een testprogramma opnemen en de testen vervolgens hergebruiken.

## in deze code en de opdracht

Er worden 3 functies getest die zijn opgenomen in checkStrings.

Voor ieder van deze functies is in ./test/main een testfunctie opgenomen.

```c
void test_trim(void)
void test_isInteger(void)
void test_isIntegerExtend(void)
void test_isMACaddress(void)
```
### test_trim() test de functie trim()

Er wordt steeds een testcase samengesteld:

```c
   {
      const char str[] = "test";                        // hier wordt de te testen string ingesteld
      const char expected[] = "test";                   // hier wordt het te verwachten resultaat ingesteld
      char dest[100] = {'\0'};                          // dit is een buffer om de functie te testen

      trim(dest, str);                                  // hier wordt de functie uitgevoerd
      TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, dest, "test 1"); // hier wordt in een macro gecontroleerd of de
                                                                  // het resultaat overeen komt met de verwachting
   }
```

Er zijn heel veel verschillende macro's beschikbaar. Kijk daarvoor in de documentatie van Unity op:

https://github.com/ThrowTheSwitch/Unity

Hier kun je ook het framework downloaden.

### nog een voorbeeld test_isIntegerExtend

Bij deze testen is een eenvoudiger methode en macro gekozen. Het resultaat van de functie is ook eenvoudiger.

```c
   TEST_ASSERT_TRUE_MESSAGE(isIntExtend("0"), "test 1");
   TEST_ASSERT_TRUE_MESSAGE(isIntExtend("123"), "test 2");
   TEST_ASSERT_TRUE_MESSAGE(isIntExtend("-123"), "test 3");
   TEST_ASSERT_TRUE_MESSAGE(isIntExtend("+123"), "test 4");
```

Deze macro test het resultaat als boolean.

Opmerking: In de code in testomgeving main.c zijn compunds gemaakt door extra { }, daarmee sluit je stukken code in.
Variabelen en definities zijn dan *local* binnen deze codeblokken.

in 8.1extra is de test van 7.2 omgezet naar Unity
