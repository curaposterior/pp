#include <stdio.h>


int potega_rek(int liczba, int wyk) {
	if (wyk == 0)
		return 1;
	else if ((wyk % 2) == 0)
		return potega_rek(liczba, wyk / 2)*potega_rek(liczba, wyk/2);
	else 
		return liczba * potega_rek(liczba, wyk / 2)*potega_rek(liczba, wyk/2);
}

int potega_iter(int liczba, int wyk) {
	int wartosc,i;
	wartosc = liczba;
	for (i=1; i < wyk; i++) {
		wartosc = wartosc * liczba;
	}
	
	return wartosc;
}

int szybka_potega(int podstawa, int wyk) {
    int wynik = 1;
    while (wyk > 0) {
        if (wyk % 2 == 1) {
            wynik *= podstawa;
        }
        podstawa *= podstawa;
        wyk /= 2;
    }
    return wynik;
}

int main(void){
	int liczba, wykladnik;
	printf("podaj wartosc i wykladnik potegi:\n");
	scanf("%d", &liczba);
	scanf("%d", &wykladnik);
	printf("iteracyjnie: %d do %d to %d\n", liczba, wykladnik, potega_iter(liczba,wykladnik));
	printf("rekurencyjnie: %d do %d to %d\n", liczba, wykladnik, potega_rek(liczba,wykladnik));
	printf("szybkie obliczanie potegi: %d do %d to %d\n", liczba, wykladnik, szybka_potega_rek(liczba, wykladnik));
	return 0;
}
