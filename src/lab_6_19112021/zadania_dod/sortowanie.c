#include <stdio.h>
#include <stdlib.h>
//sortowanie babelkowe
void bubble_sort(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tab[j] > tab[j+1]){
                int pom;
                pom = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = pom;
            }
        }
    }
} 
//sortowanie przez wstawianie
void insertion_sort(int tab[], int rozmiar) {
    for (int border=0; border < rozmiar; border++) {
        int elem = tab[border];
        int index = border - 1;
        while (index >= 0 && tab[index] > elem) {
            if (tab[index] > elem) {
                tab[index + 1] = tab[index];
                index -= 1;
            }
        }
        tab[index + 1] = elem;
    } 
}

int main() {
    int rozmiar = 10;
    int tab1[10] = {10,9,8,7,6,5,4,3,1,2};
    int tab2[10] = {10,9,8,7,6,5,4,3,1,2};
    bubble_sort(tab1, rozmiar);
    insertion_sort(tab2, rozmiar);
    for (int i = 0; i < rozmiar; i++)
        printf("%d  %d\n", tab1[i], tab2[i]);
    
    return 0;
}
