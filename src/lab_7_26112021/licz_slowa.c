#include <stdio.h>
#include <ctype.h>
#include <stdio.h>

#define DLUGOSC 1500

int licz_slowa(char str[]) {
    int i = 0, licznik = 0;
    while(str[i] != '\0'){
        if(isalpha(str[i])){
            licznik++;
            while(!isspace(str[i])){
                i++;
            }
        }
        else i++;
    }
	return licznik;
}

int licz_znaki(char str[]) {
    int licz=0;
    int i=0;
    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            licz++;
        }
    }
    return licz;
}

int main(void) {
    int liczba_slow = 0, liczba_linii = 0, liczba_znakow = 0;
    char sentence[DLUGOSC+1];
    printf("wpisz tekst z maksymalnie %d znakami\n", DLUGOSC);
    while (!(iscntrl(fgets(sentence,DLUGOSC,stdin)))) { //gwarantuje wyjscie z petli gdy uzytkownik
        liczba_slow = liczba_slow + licz_slowa(sentence);// nacisnie CTRL-Z 
        liczba_linii++;
        liczba_znakow = liczba_znakow + licz_znaki(sentence);
    }
    printf("liczba slow: %d\n", liczba_slow);
    printf("liczba linii: %d\n", liczba_linii);
    printf("liczba znakow: %d\n", liczba_znakow);
}