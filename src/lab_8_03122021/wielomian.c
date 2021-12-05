#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int potega(int liczba, int wyk) {
	if (wyk == 0)
		return 1;
	else if ((wyk % 2) == 0)
		return potega(liczba, wyk / 2)*potega(liczba, wyk/2);
	else 
		return liczba * potega(liczba, wyk / 2)*potega(liczba, wyk/2);
}

int wartosc_wielomianu(int tab_wsp[], int liczba, int stopien){
	//wspolcznynniki podane od konca (a0, a1, ..., an)
	int wartosc = 0;
	for (int i = 0; i < stopien+1; i++) {
		wartosc += tab_wsp[i] * (potega(liczba, stopien - i));
	}
	return wartosc;
}

int horner(int tab_wsp[], int x, int st) {
	int sum = 0;
	for (int i=st; i > 0; i--){
		sum = (sum + tab_wsp[i])*x;
	}
	sum = sum + tab_wsp[0];
	return sum;
}

int menu(void) {
	int opcja;
	printf("Obliczanie wartosci wielomianu: \n");
	printf("1. Standardowa metoda\n");
	printf("2. Schemat Hornera\n");
	printf("3. Porownanie czasu wykonania (1 milion razy)\n");
	scanf("%d", &opcja);
	return opcja;
}

int* wczytaj(int* tab, int rozmiar){
	printf("wczytaj wartosci do tablicy\n");
	tab = malloc(sizeof(int) * rozmiar);
	for (int i=0; i < rozmiar; i++){
		scanf("%d", &tab[i]);
	}
	return tab;
}

int main(void) {
	int opcja = menu();
	
	if (opcja == 1) {
		int st, x;
		int* tab_wsp;

		printf("podaj stopien wielomianu i x:\n");
		scanf("%d", &st);
		scanf("%d", &x);
		tab_wsp = wczytaj(tab_wsp, st + 1);
		
		printf("Wartosc wielomianu: %d", wartosc_wielomianu(tab_wsp, x, st));
	}
	else if (opcja == 2) {
		int st;
		int* tab_wsp;

		printf("podaj stopien wielomianu:\n");
		scanf("%d", &st);
		
		tab_wsp = wczytaj(tab_wsp, st + 1);

	}
	else if (opcja == 3) {
		int st, x;
		int* tab_wsp;
		
		printf("podaj stopien wielomianu i x:\n");
		scanf("%d", &st);
		scanf("%d", &x);
		tab_wsp = wczytaj(tab_wsp, st + 1);

		double timeStart1 = 0;	
		double timeStop1 = 0;
		printf("Czas wykonania dla zwyklego algorytmu obliczania:\n");
		timeStart1 = clock();	
		for (int i=0; i < 1000000; i++){
			wartosc_wielomianu(tab_wsp, x, st);
		}
		timeStop1 = clock();	
		printf("Czas: %lf\n", (timeStop1-timeStart1)/CLOCKS_PER_SEC);

		double timeStart = 0;	
		double timeStop = 0;
		printf("Czas wykonania dla schematu Hornera:\n");
		timeStart = clock();	
		for (int i=0; i < 1000000; i++){
			horner(tab_wsp, x, st);
		}
		timeStop = clock();
		printf("Czas: %lf\n", (timeStop-timeStart)/CLOCKS_PER_SEC);
	}
	else
		return 1;
	return 0;
}
