# Readme

<!--15-Mrz-20-->

`(c)` 2020 Jan Unger

<https://bw-ju.de>

## Inhalt

    css/*               Webdesign anpassen
    code/*              Quellcode
    img_orig/*          Bilder in Original: min. 2x *.jpg o. *.png
    img_auto/*
    images/*            Bilder optimiert
    latex/*             LaTeX files -> pdfs
    latex/Grafiken/*    logo u. titelbild
    latex/content/*     präambel, metadata, header, literatur.bib
    scripte/*           Powershell Scripte
    #word/*
    www/*               CMS Wordpress u. HTML5 files

    # git files
    .gitattributes, .gitconfig u. .gitignore

    # Backup files
    cd ..
    DATUM_Thema-Notiz_vVERSION.zip
    Thema-Notiz.zip
    Thema_git_log.txt

## Erste Schritte

"Readme.txt" **lesen**

**Thema** im Script `projekt.ps1` anpassen u. im Ordner

`scripte/"git.ps1" u. "backup.ps1"`

`latex/content/"metadata.tex", "zusammenfassung.tex", "literatur.bib"`

`latex/Grafiken/"titelbild.pdf"`

**Notizen** in Markdown erstellen: `min. 2x *.md`

    # PS-Script ausführen
    PS >_ projekt.ps1

    # Projekt - Website
    Start.html

## Git

### Repository clonen

    # Github
    $thema   = "c-Kurs-Notiz" # Repository
    $ADRESSE = "https://github.com/ju1-eu"
    git clone $ADRESSE/${thema}.git

    # HD
    $HD    = "C:\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    git clone $HD/${thema}.git

    # USB
    $USB   = "E:\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    git clone $USB/${thema}.git

    # RPI
    $RPI   = "\\RPI4\nas\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    git clone $RPI/${thema}.git

### Neues Repository anlegen

    # Github
    $thema   = "c-Kurs-Notiz" # Repository
    $ADRESSE = "https://github.com/ju1-eu"
    git remote add origin $ADRESSE/${thema}.git
    git push --set-upstream origin master

    # backupHD
    $HD  = "C:\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    $LESEZ = "backupHD"
    git clone --no-hardlinks --bare . $HD/${thema}.git
    git remote add $LESEZ $HD/${thema}.git
    git push --all $LESEZ

    # backupUSB
    $USB   = "E:\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    $LESEZ = "backupUSB"
    git clone --no-hardlinks --bare . $USB/${thema}.git
    git remote add $LESEZ $USB/${thema}.git
    git push --all $LESEZ

    # backupRPI
    $RPI   = "\\RPI4\nas\repos\notizenWin10"
    $thema = "c-Kurs-Notiz" # Repository
    $LESEZ = "backupRPI"
    git clone --no-hardlinks --bare . $RPI/${thema}.git
    git remote add $LESEZ $RPI/${thema}.git
    git push --all $LESEZ

### Versionsverwaltung git

sichern - löschen - umbenennen

    # sichern
    #git init
    git status
    git add .
    git commit -a
    git push     # github
    git push --all backupUSB
    git push --all backupHD
    git push --all backupRPI

    # löschen
    git rm datei o. ordner
    git rm -rf ordner
    git rm ordner -Recurse -Force

    # umbenennen
    git mv datei datei_neu

# Markdown

## Überschriften

    # Überschrift   1
    ## Überschrift  2
    ### Überschrift 3

## Code

`Quellcode`

```
	#include <stdio.h>
	int main(void) {
		printf("Hallo Welt!\n");
		return 0;
	}
```

## Quellenangabe

Zitat: vgl. \cite{monk_action_buch:2016} u. \cite{kofler_linux:2017}

    \cite{monk_action_buch:2016}
    \cite{kofler_linux:2017}
    \footnote{\url{https://de.wikipedia.org/wiki/LaTeX}}.

## Listen

**ungeordnete Liste**

- a
- b - bb
- c

  - a
  - b
    - bb
  - c

**Sortierte Liste**

1. eins
2. zwei
3. drei

   1. eins
   2. zwei
   3. drei

**Sortierte Liste**

a) a
b) b
c) c

    a) a
    b) b
    c) c

## Links

<https://google.de> oder [Google](https://google.de)

    <https://google.de>
    [Google](https://google.de)

## Absätze

Dies hier ist ein Blindtext zum Testen von Textausgaben. Wer diesen Text liest,
ist selbst schuld. Der Text gibt lediglich den Grauwert der Schrift an.
Ist das wirklich so? Ist es gleichgültig, ob ich schreibe: "Dies ist ein Blindtext"
oder "Huardest gefburn"? Kjift - mitnichten! Ein Blindtext bietet mir wichtige Informationen.

Dies hier ist ein Blindtext zum Testen von Textausgaben. Wer diesen Text liest,
ist selbst schuld. Der Text gibt lediglich den Grauwert der Schrift an.
Ist das wirklich so? Ist es gleichgültig, ob ich schreibe: "Dies ist ein Blindtext"
oder "Huardest gefburn"? Kjift - mitnichten! Ein Blindtext bietet mir wichtige Informationen.

## Texthervorhebung

**fett** _kursiv_ "Anführungsstriche"

    **fett**
    *kursiv*
    "Anführungsstriche"

## Bild

Bilder in pdf speichern, empfehlenswert für \LaTeX.

![Logo](images/winter.pdf)

    ![Logo](images/winter.pdf)

## Tabelle

| **Nr.** | **Begriffe** | **Erklärung** |
| ------: | :----------- | :------------ |
|       1 | a1           | a2            |
|       2 | b1           | b2            |
|       3 | c1           | c2            |

    | **Nr.** | **Begriffe** | **Erklärung** |
    | ------: | :----------- | :------------ |
    |       1 | a1           | a2            |
    |       2 | b1           | b2            |
    |       3 | c1           | c2            |

## Mathe

$[ V ] = [ \Omega ] \cdot [ A ]$ o. $U = R \cdot I$

    $[ V ] = [ \Omega ] \cdot [ A ]$ o. $U = R \cdot I$

$R = \frac{U}{I}$

    $R = \frac{U}{I}$
