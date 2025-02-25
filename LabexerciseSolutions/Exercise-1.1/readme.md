# Exercise-1.1
## Het maken van input en output functies om een array van structs te vullen en af te drukken.

<ol>
<li>void fillStruct(data_t *data);</li>
<li>void clearStruct(data_t *data);</li>
<li>void printStruct(const data_t *data);</li>
</ol>

### void fillStruct(**data_t *data**);
Het argument om een struct over te dragen voor een wijziging is een pointer naar de struct. Dit omdat er een call by reference moet zijn want de inhoud van de struct wordt gewijzigd.
### member assignment by structs en pointers
Voor een assignment voor een member van de struct gebruik je in de functie een pointer verwijzing (en geen dot) dus: **data->element1 = n;** data is nl. een pointer.[The -> operator dereferences the pointer (left operand) and accesses the value of a struct member (right operand).](https://en.wikipedia.org/wiki/Struct_(C_programming_language))
### gebruik van de const qualifier, ook bij pointers naar structs
Als de inhoud van een argument niet wordt gewijzigd maar alleen wordt geraadpleegd maak je gebruik van de **const** qualifier. De compiler kan dan controleren of er in de functie daadwerkelijk niets veranderd
