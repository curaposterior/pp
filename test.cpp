#include <iostream>
#include <time.h>
using namespace std;


void zad1();
void zad2();
void zad3();
int zmien(int* wsk);
void zad5a(int tab[], int n);
void zad5b(int* tab, int n);
void zad5c(int* tab, int n);
void pokaz(const int* staly_obj, int n);
void zmien_zad6(int* wsk_tab, int n);

int main() {

	//zad1();
	//zad2();
	//zad3();

	//zad4
	int wartosc = 1;
	//zmien(&wartosc);
	//zmien(&wartosc);

	//zad5
	int tablica[4] = { 5,10,15,20 };
	//zad5a(tablica, 4);
	//zad5b(&tablica[0], 4);
	//zad5c(&tablica[0], 4);


	//zad 6
	int tablica_zad6[5] = { 5,4,3,2,1 };

	pokaz(&tablica_zad6[0], 5);
	zmien_zad6(&tablica_zad6[0], 5);
	pokaz(&tablica_zad6[0], 5);

	//zad 7
	
	int wiersz, kolumna;
	cout << "Podaj ilosc wierszy i kolumn tablicy dwuwymiarowej:" << endl;
	cin >> wiersz >> kolumna;
	
	try {
		int** tab = new int*[wiersz]; //miejsce na wiersze
		for (int i = 0; i < wiersz; ++i) {
			tab[i] = new int[kolumna]; //miejsce na poszczegolne komorki
		}

		for (int i = 0; i < wiersz; i++) {
			for (int j = 0; j < kolumna; j++) {
				tab[i][j] = rand() % 100;
				cout << tab[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i<wiersz; i++)
			delete[] tab[i];
		delete[] * tab;
	}
	catch (bad_alloc) {
		cout << "Przydzielanie pamieci nie powiodlo sie" << endl;
	}
	// zwalnianie miejsca w pamieci
	

	system("PAUSE");
	return 0;
}

void zad1() {
	int tab1[6] = { 1,2,3,4,5,6 };
	double tab2[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	int* int_wsk = tab1;
	double* double_wsk = tab2;

	for (int i = 0; i < 6; i++) {
		cout << int_wsk << endl;
		cout << double_wsk << endl << endl;
		int_wsk++;
		double_wsk++;
	}
}

void zad2() {
	srand(NULL);
	int rand_arr[15];
	for (int i = 0; i < 15; i++) {
		rand_arr[i] = rand() % 100;
		cout << rand_arr[i] << " ";
	}

	int* p1 = nullptr;
	int* p2 = nullptr;
	int* p3 = nullptr;

	p1 = &rand_arr[4];
	p2 = &rand_arr[9];
	p3 = &rand_arr[10];
	cout << "" << endl;
	cout << "Odejmowanie z wyluskaniem: " << *(p1)-*(p2)-*(p3) << endl;
	cout << "Odejmowanie bez wyluskania:" << endl;
	cout << p1 - p2 << endl;
	cout << p3 - p2 << endl;
	cout << p1 - p3 << endl;
}

void zad3() {
	int tab[5] = { 1, 2, 3, 4, 5 };
	int* p_1 = nullptr; // lub p_1 = NULL;
	int* p_2 = nullptr; // lub p_2 = NULL;

	p_1 = &tab[2];
	int odp;
	cout << "Na ktory element ma wskazywac drugi wskaznik? " << endl;
	cin >> odp;

	if (odp <= 5) {
		p_2 = &tab[odp];

		if (p_2 - tab > 2.5) {
			cout << "Wskazuje na miejsce blizej konca" << endl;
		}
		else {
			cout << "Wskazuje na miejsce blizej poczatku" << endl;
		}
	}
	else {
		cout << "Wybrales indeks spoza zakresu tablicy!" << endl;
	}
}

void zad5a(int tab[], int n) {
	for (int i = 0; i < n; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
}

void zad5b(int* tab, int n) {
	for (int i = 0; i < n; i++) {
		cout << *tab << " ";
		tab++;
	}
	cout << endl;
}
void zad5c(int* tab, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(tab + i) << " ";
	}
	cout << endl;
}

int zmien(int* wsk) {
	cout << "Przed zwiekszeniem " << *wsk << endl;
	*(wsk) += 10;
	cout << "Po zwiekszeniu " << *wsk << endl << endl;

	return *wsk;
}

void pokaz(const int* staly_obj, int n) {
	for (int i = 0; i < n; i++) {
		cout << *staly_obj << " ";
		staly_obj++;
	}
	cout << endl;
	// *(staly_obj) = 0; // nie zadziala
}

void zmien_zad6(int* wsk_tab, int n) {
	for (int i = 0; i < n; i++) {
		*(wsk_tab + i) = i;
	}
}
