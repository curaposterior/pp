#include <stdio.h>
#include <stdlib.h>

#define MAX_DL_L 300
#define MAX_N_L 4

int read_line(char* linia, int max_dl);
void print_line(char* linia, int dl_linii);

int main(void) {
    char c;
    int licznik = 0;
    char tekst_wieloliniowy_2D[MAX_N_L][MAX_DL_L];
    int dl_linii_tab[MAX_N_L];

    for (int nr_l = 0; nr_l < MAX_N_L; nr_l++) {
        char* linia = tekst_wieloliniowy_2D[nr_l];
        dl_linii_tab[nr_l] = read_line(linia, MAX_DL_L-1);
    }
    printf("Wczytany tekst:\n");
    for (int nr_l = 0; nr_l < MAX_N_L; nr_l++){
        print_line(tekst_wieloliniowy_2D[nr_l], dl_linii_tab[nr_l]);
    }
    return 0;
}

int read_line(char* linia, int max_dl) {
    char c;
    int i;
    for (i = 0; i < max_dl && (c = getchar()) != EOF && c != '\n'; ++i) {
        linia[i] = c;
    }
    if (c == '\n') {
        linia[i] = c;
        ++i;
    }
    linia[i] = '\0';
    return i;
}

void print_line(char* linia, int dl_linii) {
    printf("%s", linia);
}