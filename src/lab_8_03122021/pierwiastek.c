#include <stdio.h>
#include <math.h>

#define ACC (1.e-5) //0.00010

double pierwiastek(int a) {
	if (a < 0) {
		printf("Nie da sie obliczyc pierwiastka rzeczywistego\n");
		return 1;
	}
	else if (a > ACC) {
		double pierwiastek = 1.0, temp, i = 0;
		do {
			i++;
			temp = pierwiastek;
			pierwiastek = 0.5 * (temp + a/temp); //zastosowany wzor herona
		}
		while (fabs(pierwiastek*pierwiastek - a)/a > ACC); //liczenie pierwiastka do podanej dokladnosci
		printf("Obliczony pierwiastek %lf, dokladny pierwiastek %lf\n", pierwiastek, sqrt(a));
		return pierwiastek;
	}
	else {
		printf("Zle dane\n");
		return 1;
	}
}

int main(){
	double liczba;
	scanf("%lf", &liczba);
	pierwiastek(liczba);
	return 0;
}
