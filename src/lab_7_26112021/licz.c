#include <stdio.h>

void wypisz_liczby(int ndigit[], int rozmiar){
	int i;
	printf("\ncyfry:\n");
	for (i = 0; i < rozmiar; i++)
		if (ndigit[i] != 0)
			printf("'%d' = %d\n", i, ndigit[i]);
}

void wypisz_alphabet(int tablica_duze[], int tablica_male[], int rozmiar){
	int i;
	//wypisanie duzych i malych liter:
	printf("Duze litery:");
	for (i=0; i < rozmiar; i++){
		if (tablica_duze[i] != 0)
			printf("\n%c: (%d) ", i + 'A', tablica_duze[i]);
			for(int j=0; j < tablica_duze[i]; j++)
				printf("*");
	}
	printf("\nMale litery:");
	for (i=0; i < rozmiar; i++){
		if (tablica_male[i] != 0)
			// printf("%c: %d\n", i + 'a', tablica_male[i]);
			printf("\n%c: (%d) ", i + 'a', tablica_male[i]);
			for(int j=0; j < tablica_male[i]; j++)
				printf("*");
	}
}

int main() {
	int i, nline=0,nchar=0, nwhite=0;
	int ndigit[10] = {0};
	int c_alphabet[26] = {0};
	int s_alphabet[26] = {0};
	int c;
	while ((c = getchar()) != EOF){
		if (c >= 65 && c <= 90)
			c_alphabet[c-'A']++;
		else if (c >= 97 && c <= 122)
			s_alphabet[c-'a']++;
		else if (c == '\n')
			nline++;
		else if (c >= 48 && c <= 57)
			ndigit[c-'0']++;
		else
			nwhite++;
	}
	wypisz_alphabet(c_alphabet, s_alphabet, 26);
	wypisz_liczby(ndigit, 10);
	printf("liczba nowych linii %d\n", nline);
	printf("liczba bialych znakow %d\n", nwhite);
}
