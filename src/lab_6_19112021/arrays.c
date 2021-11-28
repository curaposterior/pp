#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_TABLICY 10
#define ROZMIAR_STRING 10

void wypisz_elementy(int tablica[], int rozmiar) {
	int i;
	for (i=0; i<rozmiar; i++){
		printf("%d ", tablica[i]);
	}
}
void nadaj_wartosc(int tablica[], int rozmiar) {
	int i;
	for (i=0; i < ROZMIAR_TABLICY; i++){
		tablica[i] = i;
		printf("%d\n", tablica[i]);
	}
}

void nadaj_wartosc_while(int tablica[], int rozmiar) {
	int i = 0;
	while (i < rozmiar) {
		tablica[i] = i;
		printf("%d ", tablica[i]);
		i += 1;
	}
}
float srednia_liczb_w_tablicy(int tablica[], int rozmiar) {
	float suma;
	suma = suma_elementow(tablica, rozmiar);
	float srednia = suma / rozmiar;
	return srednia;
}

void wczytaj_wartosc(int rozmiar) {
	int counter = 0;
	int tab[10];
	printf("\n\nWczytaj wartosci do tablicy:\n");
	while (counter < ROZMIAR_TABLICY) {
		scanf("%d", &tab[counter]);
		counter++;
	}
	int i;
	printf("Wypisuje elementy wczytane z klawiatury\n");
	for (i=0; i<rozmiar; i++){
		printf("%d ", tab[i]);
	}
}
//dynamiczna alokacja pamieci
int* wypelnij_losowo(int* tab, int rozmiar){
	srand(time(NULL));
	tab = malloc(sizeof(int) * rozmiar); // rezerwacja miejsca w pamieci
	int i;
	for (i=0; i < rozmiar; i++){
		tab[i] = rand() % 100;
	}
	return tab;
}

int wartosc_maks_tab(int tab[], int rozmiar){
	int maks_pom = tab[0];
	for (int i=0; i < rozmiar; i++){
		if (maks_pom < tab[i])
			maks_pom = tab[i];
	}
	return maks_pom;
}

int suma_elementow(int* tab_wsk, int rozmiar){
	int i;
	int suma;
	
	suma = 0;
	for (i=0; i < rozmiar; i++){
		suma = suma + tab_wsk[i];
	} 
	return suma;
}

void losowy_string(int* tab, int rozmiar) {
	srand(time(NULL));
	tab = malloc(sizeof(int) * rozmiar); // rezerwacja miejsca w pamieci
	int a,b;
	a = 33, b = 126; //fragment tablicy ascii ze znakami
	for (int i=0; i < rozmiar; i++){
		int liczba_losowa = a + rand()%(b-a+1); // pseudolosowość
		tab[i] = liczba_losowa;
	}
	printf("\nLosowy string:\n");
	for (int i=0; i < rozmiar; i++) {
		printf("%c", tab[i]);
	}
	printf("\n");
}

void znajdz_pierwsza_wartosc(int tab[], int rozmiar, int liczba) {
	int found;
	printf("\nWyszukiwanie liczby w tablicy (pierwszy znaleziony indeks):\n");
	for (int i=0; i < rozmiar; i++) {
		if (liczba == tab[i]) {
			printf("Znaleziono liczbe: indeks: %d, liczba: %d\n", i, tab[i]);
			found = i;
			break;
		}
	}
}

void znajdz_wszystkie_wartosci(int tab[], int rozmiar, int liczba) {
	printf("\nWyszukiwanie liczby w tablicy (wszystkie znalezione indeksy):\n");
	for (int i=0; i < rozmiar; i++) {
		if (liczba == tab[i]) {
			printf("Znaleziono liczbe: indeks: %d, liczba: %d\n", i, tab[i]);
		}
	}
}

int main() {
	//nadawanie wartosci tablicy
	int tab[ROZMIAR_TABLICY] = {0};
	nadaj_wartosc(tab, ROZMIAR_TABLICY);
	//nadawanie wartosci tablicy w petli while
	nadaj_wartosc_while(tab, ROZMIAR_TABLICY);

	/* losowe wypelnienie tablicy i wyswietlenie
	jej elementow: */
	int* tab_wskaznik;
	int rozmiar = 0;
	printf("\nPodaj rozmiar tablicy\n");
	scanf("%d", &rozmiar);
	tab_wskaznik = wypelnij_losowo(tab_wskaznik, rozmiar);
	printf("Pseudolosowe elementy:\n");
	wypisz_elementy(tab_wskaznik, rozmiar);

	//maksymalna wartosc tablicy tab_wskaznik
	printf("\n\nMaksymalna wartosc tablicy tab_wskaznik:\n%d", wartosc_maks_tab(tab_wskaznik, rozmiar));

	//suma elementow tablicy tab_wskaznik
	printf("\nSuma elementow tablicy typ_wskaznik: %d\n", suma_elementow(tab_wskaznik, rozmiar));

	//srednia elementow typ_wskaznik z porownaniem
	printf("\nSrednia elementow tablicy tab_wskaznik: %f", srednia_liczb_w_tablicy(tab_wskaznik, rozmiar));
	
	//wczytaj wartosci z klawiatury
	wczytaj_wartosc(ROZMIAR_TABLICY);
	
	//losowe wartosci typu char:
	int* tablica_char;
	losowy_string(tablica_char, ROZMIAR_STRING);

	// wyszukiwanie wartosci w tablicy (wypisanie pierwszego indeksu wartosci)
	int tab_znajdz[ROZMIAR_TABLICY] = {1,5,8,3,0,7,99,12,3,76};
	int liczba = 3;
	znajdz_pierwsza_wartosc(tab_znajdz, ROZMIAR_TABLICY, liczba);
	//wypisanie wszystkich znalezionych wartosci
	znajdz_wszystkie_wartosci(tab_znajdz, ROZMIAR_TABLICY, liczba);

	return 0;
}