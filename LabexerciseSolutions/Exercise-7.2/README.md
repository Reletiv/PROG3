# Exercise 7.2 Test cases

Voor **white-box testen** van de gegeven C-code:
```c
if (a && b || c)
{
    // code
}
```
Moet je testgevallen maken die alle mogelijke combinaties van de variabelen `a`, `b` en `c` dekken. Dit zorgt ervoor dat alle onderdelen van de logische expressie worden getest, inclusief het gedrag van **short-circuit evaluatie** bij de logische operatoren.
1. **a = true, b = true, c = true**  	resultaat true
2. **a = true, b = true, c = false**  resultaat true
3. **a = true, b = false, c = true**  resultaat true
4. **a = true, b = false, c = false**  resultaat false
5. **a = false, b = true, c = true**  resultaat true
6. **a = false, b = true, c = false** resultaat false
7. **a = false, b = false, c = true** resultaat true
8. **a = false, b = false, c = false** resultaat false

je kunt een waarheidstabel opstellen om te testen.

In main.c in deze directory is een voorbeeld test
op genomen.

