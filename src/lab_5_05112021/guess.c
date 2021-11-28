#include <stdio.h>
#include <time.h>

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