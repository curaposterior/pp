#include <stdio.h>
#include <stdlib.h>

#define MAX_N_L 2
#define MAX_N_C 30

typedef struct linia_tekstu {
    char* znaki; 
    int dl_linii;
} linia_tekstu;


int readline(char* linia, int dl_max);
void printline(char* linia, int dl);


int main() {
    int counter = 0;
    int dl_linii_tab[MAX_N_L];

    //definiowanie potrzebnych tablic (tablica wskaznikow i tablica struktur)
    char* tekst_wieloliniowy_tab_wsk[MAX_N_L] = {NULL};
    linia_tekstu tekst_wieloliniowy_struct[MAX_N_L];    
    
    for (int i = 0; i < MAX_N_L; i++) {
        
        //alokowanie miejsca na stercie dla kolejnych linii tekstu
        tekst_wieloliniowy_tab_wsk[i] = malloc(sizeof(char) * MAX_N_C);
        tekst_wieloliniowy_struct[i].znaki = malloc(sizeof(char) * MAX_N_C);

        //stworzenie wskaznika do linii tekstu i wczytanie linii z stdin
        char *text_line = tekst_wieloliniowy_tab_wsk[i];
        int dl_l = readline(tekst_wieloliniowy_struct[i].znaki, MAX_N_C);

        //jesli wczytalismy jakas zawartosc zapisujemy ja do struktury
        if (dl_l > 0) {
            tekst_wieloliniowy_struct[i].dl_linii = dl_l;
            dl_linii_tab[i] = dl_l; // zapisujemy dlugosc w tablicy
            counter++;
        }
        else {
            printf("\nWypisywanie linii...\n\n");
            break;
        }
    }
    //wypisywanie zawartosci tablicy wskaznikow:
    for (int i = 0; i < counter; i++) {
        printline(tekst_wieloliniowy_struct[i].znaki, dl_linii_tab[i]);
    }

    //czyszczenie pamieci
    for (int i = 0; i < counter; i++) {
        free(tekst_wieloliniowy_tab_wsk[i]);
        free(tekst_wieloliniowy_struct[i].znaki);
    }
    return 0;
}

//funkcja wczytujaca linie tekstu
int readline(char* linia, int dl_max) {
    char c;
    int i;
    for (i = 0; i < dl_max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        linia[i] = c;
    }
    linia[i] = '\0';
    if (linia[0] == '\n') {
        linia[0] = '\0';
        return -1;
    }
    else
        return i;
}

//funkcja wypisujaca tekst
void printline(char* linia, int dl) {
    printf("%s (dlugosc: %d)\n", linia, dl);
}