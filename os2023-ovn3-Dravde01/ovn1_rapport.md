# Operativsystem 2022 - Lösning till datorövning 3, uppgift 1

**Namn:**

**Datum:**

----


## Fråga 1: Är programmet deterministiskt?

Nej, eftersom det finns ett element av slumpmässighet i programmet. Programmets output kommer, trots samma input, inte vara samma varje gång man kör det eftersom skeduleraren varje gång bestämmer olika gällande i vilken ordning trådarna ska exekveras.

## Fråga 2: Då du kör programmet, stöder det dina slutsatser i punkt 1 ovan? 

Ja, efter ett antal körningar så ser man att vissa rader printas vid olika tillfällen i de olika körningarna.

## Fråga 3: Varför bildar denna loop en kritisk sektion i koden?

Eftersom loopen innehåller den globala variabeln 'count' som kommer vilja accesseras av flera trådar samtidigt och därmed leda till kapplöpning.

## Fråga 4: Förklara sambandet mellan `count`, `UPDATE_COUNT` och `N_PTHREADS` och varför `count` inte alltid får rätt värde till slut

'UPDATE_COUNT' och 'N_PTHREADS' är variabler som vi definierar i den skilda header-filen 'ovn1.h'. Om man multiplicerar dem får man totala antalet körningar/inkrementeringar som borde göras av programmet. 'count' representerar däremot det verkliga antalet körningar/inkrementeringar som gjordes av programmet. Sambandet mellan dessa kan alltså representeras som förhållandet i procent genom att ta:
'count / (UPDATE_COUNT * N_PTHREADS) * 100'

'count' blir inte alltid rätt till slut till följd av kapplöpningen mellan trådexekveringarna som sker. Det vill säga då flera trådar försöker komma åt att modifiera eller använda variabeln 'count' så leder det ibland till att oförutsägbara saker sker med dess data. I det här fallet så går inte alla exekveringar igenom och därmed blir 'count' lägre än det förutspådda talet.

## Fråga 5: Ett dåligt barriäralternativ istället för `pthread_join` är att låta programmet sova en viss tid med `sleep`-kommandot. Varför är inte detta en bra idé?

Eftersom det kan påverka hela programmets prestanda. En fastsatt sovtid kan antingen leda till att vissa trådar inte hinner exekvera färdigt (för kort sovtid) eller att överloppstid introduceras vilket gör hela exekveringen långsammare (för lång sovtid). 'pthread_join' väntar istället dynamiskt tills en tråd har terminerats.
