# Readme

<!--7-Mrz-20-->

## Hinweis

Projekt getestet unter Win10

## PowerShell

<https://github.com/PowerShell/PowerShell/releases>

    Shell öffnen:
    PS-Version: $PSVersionTable

## Editor - Visual Studio Code

<https://code.visualstudio.com/download>

- Shell öffnen: file Auswahl `<Alt + Strg + O>`
- mehrfaches Editieren `<Alt + Mausklick>`
- Einzug: 2 (Leerzeichen), Codierung: UTF-8, Zeilenende: LF (Linux)

## C/C++ Compiler & Make

Compiler <http://www.mingw.org/>

Make
<http://gnuwin32.sourceforge.net/packages/make.htm>

## Makefile

    # ju  6-Mrz-20  Makefile - Win10
    # *.c
    TARGETS=\
        halloWelt.exe\
        Main.exe \
    #-----------------------------------
    # c
    CC:=gcc
    CDEBUG=-g3 -Wextra -Wno-missing-field-initializers -std=c18 # -Wall
    CRELEASE=-std=c18 -O2
    # Bibliothek
    #CLIBS=-lz bib.c bib.h -lm
    CLIBS=-lm
    # c++
    CXX:=g++
    CXXDEBUG=-g3 -Wextra -Wno-missing-field-initializers -std=c++2a   # -Wall
    CXXRELEASE=-std=c++2a -O2

    all: $(TARGETS)
    # gcc hallo.c -o hallo.exe
    %.exe: %.c
        $(CC) $(CDEBUG) $(CLIBS) $< -o $@

    # g++ hallo.cpp -o hallo.exe
    %.exe: %.cpp
        $(CXX) $(CXXDEBUG) $(CLIBS) $< -o $@

    # Main.c -> Release o. Debug
    release: Main.o #bib.o
        $(CC) $(CRELEASE) Main.c -o MainRelease.exe

    debug: Main.o #bib.o
        $(CC) $(CDEBUG)   Main.c -o MainDebug.exe

    Main.o: Main.c
        $(CC) -c Main.c

    #bib.o: bib.c
    #	$(CC) -c bib.c

    clean:
        #rm -r *.exe -Force
        #rm -rf *.exe *~ *.o
        rm halloWelt.exe
        rm Main.exe
        rm Main.o
        rm MainRelease.exe
        rm MainDebug.exe

## Programm erstellen

    make
    make clean

## Git - Versionieren

<https://git-scm.com/downloads>

    git init
    git add .
    git commit -am "Projekt start"
    git commit -a
    # letzten Commit rueckgaengig machen
    git commit --amend

    # Github - Repository anlegen
    $thema   = "C-Komplettkurs" # Repository
    $ADRESSE = "https://github.com/ju1-eu"
    git remote add origin $ADRESSE/${thema}.git
    git push --set-upstream origin master

    # Github - Repository clonen
    $thema      = "C-Komplettkurs" # Repository
    $ADRESSE    = "https://github.com/ju1-eu"
    git clone $ADRESSE/${thema}.git

    git pull
    git push

    git st
    git lg
