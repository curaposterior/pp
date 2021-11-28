#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SKALAR double
#define SMALL_N 1.e-20 //tolerancja do ktorej dane sa 'wlasciwe'

void zamien_switch() {
	char c;
	for (;;) {
		printf("\nWprowadz cyfre od 0 do 5: (k - konczy dzialanie)\n");
		scanf(" %c", &c);
		if (c == '0')
			printf("Wprowadzono 0\n");
		else if (c == '1')
			printf("Wprowadzono 1\n");
		else if (c == '2')
			printf("Wprowadzono 1 lub 2\n");
		else if (c == '3')
			printf("Wprowadzono 3\n");
		else if ((c == '4') || (c == '5'))
			printf("Wprowadzono 4 lub 5\n");
		else if (c == 'k')
			break;
		else
			printf("Wprowadzono: znak spoza zakresu 0-5\n");
	}
}

int rownanie_kwadratowe() {
	//rownanie w postaci ax^2 + bx + c = 0
	SKALAR a, b, c;
	
	//pobranie wspolczynnikow
	printf("Podaj po kolei parametry a, b, i c\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	printf("Wprowadzone parametry %lf %lf %lf\n", a, b, c);
	
	//sprawdzenie poprawnosci wprowadzonych danych
	if (fabs(a) < SMALL_N && fabs(b) < SMALL_N){
		printf("a i b zbyt bliskie zera\nWprowadz inne dane\n");
	}
	else if (a == 0) {
		float rozw = -c / b;
		printf("Rowanie liniowe\nRozwiazaniem jest: %f\n", rozw);
	}
	//obliczanie miejsc zerowych
	else {
		SKALAR delta;
		delta = b*b - 4*a*c;
		
		if (delta < 0) {
			printf("Nie da sie obliczyc pierwiastkow rzeczywistych\n");
		}
		else if (delta == 0)
			printf("Jeden pierwiastek rzeczywisty: %f\n", -b/(2*a));
		else {
			SKALAR sqrt_delta = sqrt(delta);
			long int x1 = (-b-sqrt_delta)/(2*a);
			long int x2 = (-b+sqrt_delta)/(2*a);
			printf("x1: %.12le, x2: %.12le\n");
			
			printf("\nsprawdzenie poprawnosci wynikow\n");
			SKALAR wynik1, wynik2;
			wynik1 = a*(x1 * x1) + b*x1 + c;
			wynik2 = a*(x2 * x2) + b*x2 + c;
			printf("wynik po podstawieniu x1: %li\n", wynik1);
			printf("wynik po podstawieniu x2: %li\n", wynik2);
		}
	}
}

int zgadywanie_liczby() {
	printf("\nzgadnij liczbe z przedzialu 0-99\n\n");
	//resetowanie ziarna
	srand(time(NULL)); //nie jest bezpieczne kryptograficznie

	int losowa_liczba, liczba;
	losowa_liczba = rand() % 100;

	for (;;) {
		printf("Wprowadz swoja liczbe:\n");
		scanf("%d", &liczba);
		if (liczba == losowa_liczba) {
			printf("ZGADLES LICZBE: %d\nGRATULACJE!\n", losowa_liczba);
			break;
		}
		else if (liczba > losowa_liczba) {
			printf("twoja liczba jest za duza\n\n");
		}
		else if (liczba < losowa_liczba) {
			printf("twoja liczba jest za mala\n\n");
		}
		else 
			printf("zle dane\n");
	}
}

int main(void) {
	printf("wybierz funkcje, ktora chcesz uzyc:\n");
	printf("1. zamien_switch()\n");
	printf("2. rownanie_kwadratowe()\n");
	printf("3. zgadywanie_liczby()\n");
	char c = getchar();
	switch (c) {
		case '1':
			zamien_switch();
			break;
		case '2':
			rownanie_kwadratowe();
			break;
		case '3':
			zgadywanie_liczby();
			break;
		default:
			printf("nic nie zostalo wybrane");
			break;
	}
	return 0;
}

