#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void wypisz(char tab[], int rozmiar){
	for(int i = 0; i < rozmiar; i++){
		printf("%c", tab[i]);

	}
}
void main(){

	int rozmiar = 11;
	//char slowo[rozmiar];
	//char pobrane[rozmiar];

	char haslo[] = "Informatyka";
	char odgadnieteHaslo[] ="-----------";

	char literka;
	_Bool znaleziono = false;
	_Bool wygrana = true;

	//scanf(" %s", &pobrane);
	//fgets(pobrane, 50, stdin);
	//printf("%s\n", haslo);

	//logika gry
	while(1){
		znaleziono = false;	//odgornie zakladamy, ze nie znajdziemy litery
		wygrana = true;		//zakladamy wygrana

		wypisz(odgadnieteHaslo, rozmiar);

		printf("\n");
		printf("Podaj litere\n");
		scanf(" %c", &literka);
		for(int i = 0; i < rozmiar; i++){
			if(literka == haslo[i]){
				odgadnieteHaslo[i] = haslo[i];
				znaleziono = true;
			}
		}
		if(!znaleziono){
			printf("Litera nie zawiera sie w hasle\n");
		}
		for(int i = 0; i < rozmiar; i++){
			if(odgadnieteHaslo[i] == '-'){
				wygrana = false;
			}
		}
		if(wygrana){
			printf("Wygrales!!!\n");
			break;
		}
	}
}
