#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*
Do poszczegolnych zadan sa zaimplementowane funkcje.
Kazdy blok funkcji jest przydzielony do ktoregos z 
zadan.
*/

//zad1
void bubbleSort(int* A, int n);
void swap(int* pa, int* pb);
void zad1_main();

//zad 2
int* smallerInt(int* pa, int* pb);
void zad2_main();

//zad 3
double* zwroc();

//zad 4
int sumaRoznicKwadratow(int* tab1, int* tab2, int n);
int* wczytaj(int* tab, int rozmiar);
void zad4_main();

//zad 5
void maleNaDuze(int n);
void zad5_main();

//zadanie 6
void dwuwymiaroweTablice(int n, int m);
void zad6_main();

int main(void) {
    zad1_main();
    zad2_main();
    zad4_main();
    zad5_main();
    zad6_main();
    return 0;
}


//zadanie 1
void zad1_main() {

    int tab[10] = {10,9,8,7,6,5,4,3,2,1};
    int* ptab = tab;

    bubbleSort(ptab, 10);

    printf("posortowana tablica:\n");

    for (int i=0; i < 10; i++)

        printf("%d ", tab[i]);

    printf("\n");
}

void bubbleSort(int* tab, int n) {

    for (int i=0; i < n-1; i++) {

        for (int j=0; j < n-1; j++) {

            if (tab[j] > tab[j+1])

                swap(&tab[j], &tab[j+1]);
        }
    }
}

void swap(int* px, int* py) {
    int temp;

    temp = *px;

    *px = *py;

    *py = temp;
}

//zadanie 2
int* smallerInt(int* pa, int* pb) {
    int* smaller = NULL;

    if (*pa > *pb) 

        smaller = pb;

    if (*pa < *pb)

        smaller = pa;

    if (*pa == *pb) 

       printf("liczby sa takie same\n");

    return smaller;
}

void zad2_main(void) {
    int a = 10, b = 5;

    int* pa;
    int* pb;
    int* small;

    pa = &a, pb = &b;

    small = smallerInt(pa, pb);
    
    printf("%d", *small);
}

//zadanie 3

double* zwroc() {

    double* lp;
    double l = 2.5;

    lp = &l;

    return lp;
}

//zadanie 4 

int sumaRoznicKwadratow(int* tab1, int* tab2, int n) {
    int sum = 0;
    
    for (int i=0; i < n; i++) {

        sum += pow((tab1[i] - tab2[i]), 2);
    }

    return sum;
}

int* wczytaj(int* tab, int rozmiar) {
	printf("wczytaj wartosci do tablicy\n");

	tab = malloc(sizeof(int) * rozmiar);

	for (int i=0; i < rozmiar; i++){

		scanf("%d", &tab[i]);
	}

	return tab;
}

void zad4_main() {
    int n, suma;
    int* tab1;
    int* tab2;

    printf("\npodaj rozmiar tablic: ");

    scanf("%d", &n);

    tab1 = wczytaj(tab1, n);
    tab2 = wczytaj(tab2, n);

    suma = sumaRoznicKwadratow(tab1, tab2, n);

    printf("Suma roznic kwadratow wynosi: %d\n", suma);
}

//zadanie 5

void maleNaDuze(int n) {
    char* tab;
    char pom;

    tab = malloc(sizeof(char) * n);

    printf("Wczytaj wartosci do tablicy:\n");

    for (int i=0; i < n; i++) {

        scanf(" %c", &tab[i]);

    }

    printf("Tablica po zamianie liter na duze: \n");
    for (int i=0; i < n; i++) {

        tab[i] = toupper(tab[i]);

        printf("%c ", tab[i]);
    }
    free(tab);
}

void zad5_main() {
    int n;

    printf("podaj rozmiar tablicy: ");

    scanf("%d", &n);

    maleNaDuze(n);

    printf("\n");
}

//zadanie 6
void dwuwymiaroweTablice(const int n, int m) {
    //stworzenie dynamicznej tablicy:
    int* tab2D[n];

    for (int i = 0; i < n; i++)

        tab2D[i] = (int*)malloc(m * sizeof(int));

    int count = 0;

    for (int i = 0; i < n; i++) 

        for (int j = 0; j < m; j++) 

            tab2D[i][j] = (i + 1) * (j + 1); //dodałem po 1 żeby ładnie wyglądało
    
    printf("tablica dwuwymiarowa:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++)

            printf("%d ", tab2D[i][j]);

        printf("\n");
    }
    free(tab2D);
}

void zad6_main() {
    int n, m;

    printf("Podaj rozmiar tablicy dwuwymiarowej (n x m):\n");

    scanf(" %d %d", &n, &m);

    dwuwymiaroweTablice(n, m);
}