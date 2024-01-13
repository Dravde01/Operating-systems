[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/_OviPKwQ)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=12833417)
# Operativsystem 2023: Datorövning 1

Den grundläggande koden och testerna finns i repositoryn från början. Du får skapa egna filer, men huvudfilerna (där `main`-funktionen finns) ska heta `ovn*.c`, där * är uppgiftsnummern. Du får även skapa egna branches, men din lösning ska lämnas in på `main`-branchen.

## Automatiska tester

Uppgiften kommer till viss del att bedömas automatiskt beroende på om de program du gjort uppfyller vissa test. 

Första gången ni klonar er repo (eller startar den i Codespaces) så kommer inte de automatiska testerna (som är en git-submodul i katalogen test) att ha klonats. För att göra det här skriv följande kommandon i terminalen:
```
~ git submodule update --init --recursive
~ git submodule update --remote
```
Ifall testerna har uppdaterats (t.ex. om det varit någon bugg i något av testerna) kör följande kommando för att uppdatera till senaste version: 
```
~ git submodule update --remote
```
Det lönar sig att köra det här kommandot före du skickar in uppgiften för att verifiera att du har senaste test-versionen.

## Inlämning
Den version du har på `main`-branchen då tiden gått ut är den som bedöms. Ändringar som görs senare beaktas nödvändigtvis inte.

Före inlämning se till att du har en fil `student.txt` som innehåller en rad enligt följande mönster:

```git_användar_namn ditt hela namn```

Du får inte använda extern kod (förutom standard C-bibliotek) om det inte specifikt nämns i uppgiftstexten.

**Att göra egna modifikationer i filerna i test-katalogen (eller .gitmodules-filen eller ändra på testerna i Makefile) räknas som fusk!** 

Skapa en klar historik över hur du har löst uppgifterna genom att göra kontinuerliga commits till repositoryn.

## Bedömning 
- Om ditt program inte kompilerar får du noll poäng för den uppgiften. 
- Den automatiska bedömningen som görs är nödvändigtvis inte slutgiltig. 
- Automatisk plagiatgranskning kan köras på koden.

## Bakgrundsinfo
- Det kan löna sig att jämföra med en ASCII-tabell.
- Tips: `(int) 'a'` ger ASCII-koden (i decimalform) för bokstaven lilla a.

## Uppgift 1. Hälsningsfras (max 2 p)

Modifiera filen `ovn1.c` så att programmet tar som input en persons namn (ett ord i ASCII, t.ex. Anna) och skriver ut "Hej Anna!". 

### Exempel

```
~ ./ovn1 Anna
Hej Anna!
```
Obs! Verifiera att programmet inte kraschar om du inte ger in något input, dvs. bara kör `./ovn`.

Programmet kompileras med `make ovn1`. Jämför med filen `Makefile` för att förstå vad detta kommando gör. 

### Bedömning: 
- 2 poäng om ditt program skriver ut korrekt sträng. 

### Testning
Du kan testa att ditt program fungerar med `make test-ovn1`.

## Uppgift 2. Lång hälsningsfras (max 2 p)

Vidareutveckla din lösning till uppgift 1 så att man nu kan ge in ett namn som kan bestå av flera ord (t.ex. Anna Alma Anka) och skriver ut "Hej Anna Alma Anka!". Obs! Spara programmet i filen `ovn2.c`. Om inget ord ges som input ska ditt program (`main`-funktionen) returnera med felkoden `1` (dvs. `return 1;`). Om inputen är mer än 100 ord ska ditt program returnera med felkoden `2`. 

### Exempel

```
~ ./ovn2 Anna Alma Anka
Hej Anna Alma Anka!
```

### Bedömning: 
- Totalt 2 poäng om ditt program skriver ut korrekt sträng och/eller returnerar statuskoderna enligt beskrivning. 

### Testning
Du kan testa att ditt program fungerar och `make test-ovn2`.


## Uppgift 3. Räkna tecken (max 6 p)

Modifiera programmet i filen `ovn3.c` så att det räknar tecken i den textfil i ASCII-format vars filnamn ges som input. Om inget filnamn ges som input ska ditt program (`main`-funktionen) returnera med felkoden `1` (dvs. `return 1;`). 

Obs! Det finns vissa specialtecken som vi inte vill ska räknas med: mellanrum (' ') (radbryning ('\r', '\n') och tabbar ('\t').


### Bedömning: 
- Totalt 6 poäng om ditt program fungerar och ignorerar tecken som '\r', '\n', '\t' och ' ' (mellanslag).  
- Extra 2 poäng om du dessutom skapar en version i `ovn3-chars.c` som endast räknar bokstäver, siffror och specialtecken (ASCII element 32-126).

### Testning
Programmet kan testas med `make test-ovn3` och `make test-ovn3-chars`.

## Uppgift 4. Bokstavsfrekvens (max 10 p)

Skapa ett program i filen `ovn4.c` som räknar frekvensen av bokstäver a-z i den textfil i ASCII-format vars filnamn ges som input och skriver ut dessa till en resultatfil enligt följande mall:
```
a 1
b 2
...
z 2
```
Du ska alltså inte beakta stora och små bokstäver skilt. Du ska inte skriva ut rader med sådan bokstav som saknas. Om inget ord ges som input ska ditt program (`main`-funktionen) returnera med felkoden `1` (dvs. `return 1;`). 

Om du vill ha ytterligare poäng implementera dessutom följande funktionalitet i en skild, fristående fil `ovn4-sort.c`:
- Sortera raderna enligt fallande frekvens och sedan i bokstavsordning om flera bokstäver har samma frekvens. Obs! Din lösning behöver inte vara effektiv.

### Bedömning: 
- Totalt 6 poäng om ditt program `ovn4` fungerar och skriver ut rapporten i bokstavsordning a-z.
- Extra 4 poäng om ditt program `ovn4-sort` skriver ut rapporten över bokstavsfrekvensen enligt fallande frekvensordning och sedan enligt bokstavsordning för bokstäver med samma frekvens.

### Testning
Programmet kan testas med `make test-ovn4` och `make test-ovn4-sort`. 
