#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROZMIAR 8

bool sprawdzanie_litery(int litera, char haslo[]) {
    bool flag = false;
    for (int i = 0; i < strlen(haslo); i++){
        if (litera == haslo[i]){
            flag = true;
        }
    }
}

void wypisz_tab(char tab[], int rozmiar){
    for (int i=0; i < rozmiar; i++){
        printf("%c", tab[i]);
    }
    printf("\n");
}

int main() {

    char haslo[ROZMIAR] = "Algorytm";
    char odgadniete[ROZMIAR] = "********";
    char litera;

    //flagi logiczne
    
    for (;;)
    {
        //rob cos
    }
    return 0;
}