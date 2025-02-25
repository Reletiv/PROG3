# exercise 3.1 Command line arguments
Het gaat hier om het gebruik van de command line arguments die als argumenten aan de functie main() worden meegegeven.

**int main(int argc, char *argv[])**

**argc** bevat het aantal argumenten inclusief de programmanaam.
**\*argv[]** is een pointer naar een array van strings waarin de argumenten als string zijn opgenomen.

## argv[] gebruiken

Ieder argument kun je als string eenvoudig benaderen door argv[index]

In de uitwerking wordt hier uitgebreid gebruik van gemaakt, zie de lus die alle argumenten optelt.

## ternary operator

Opnieuw hier gebruik van **ternary operator** 

**isInt(argv[i])?"Integer":"Non Integer"**

Resultaat: 
als isInt(argv[i]) waar is dan wordt Integer gebruikt

als isInt(argv[i]) niet waar is dan wordt Non Integer gebruikt

Dus er is een conditie voor het ?
Indien waar, hetgeen er direct op volgt
Indien niet waar, hetgeen achter de : staat