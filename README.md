# W-rfelSimulator2
Hier gibt es bessere Version des Würfelsimulators

Es ist keine Installation nötig, das Programm läuft von Kommandozeile aus

Um das Programm für Windows zu kompilieren bitte folgendes Kommando nutzen:
Wenn gcc installiert ist:
gcc -D Windows -o wuerfeln.exe main.c defence.c
Andernfalls bitte ein equivalenten compiler nutzen


Um es von Linux zu Windows zu crosskompilieren wird der mingw gcc crosscompiler benötigt:
x86_64-w64-mingw32-gcc -D WINDOWS -o wuerfeln.exe main.c defence.c

Für Linux auf Linux:
gcc -o wuerfeln main.c defence.c

