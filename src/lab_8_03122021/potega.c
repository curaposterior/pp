#include <stdio.h>

/*to do
- zaimplementowac zliczanie czasu wykoniania poszczegolnych
funkcji (zrobic porownanie)
*/
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

int szybka_potega_rek(int podstawa, int wyk){
	int a;
	if (wyk == 0)
		return 1;
	if (wyk % 2 != 0)
		return (podstawa*szybka_potega_rek(podstawa,wyk-1));
	else {
		a = szybka_potega_rek(podstawa, wyk/2);
	}
	return a * a;
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