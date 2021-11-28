#include <stdio.h>
#include <string.h>

#define ROZMIAR 100

void caesar_encode(char plaintext[100], int k)
{
    k = k % 26;
    
    for (int i=0; plaintext[i] != '\0'; i++) {
        char znak;
        znak = plaintext[i];
        if (znak >= 'a' && znak <= 'z'){
            znak = znak + k;
            if (znak > 'z'){
                znak = znak - 'z' + 'a' - 1;
            }
            plaintext[i] = znak;
        }
        else if (znak >= 'A' && znak <= 'Z') {
            znak = znak + k;
            if (znak > 'Z') {
                znak = znak - 'Z' + 'A' - 1;
            }
            plaintext[i] = znak;
        }
    }
    printf("%s\n", plaintext);
}

void caesar_decode(char ciphertext[100], int k) {
    k = k % 26;
    
    for (int i=0; ciphertext[i] != '\0'; i++) {
        char znak;
        znak = ciphertext[i];
        if (znak >= 'a' && znak <= 'z'){
            znak = znak - k;
            if (znak < 'a'){
                znak = znak - 'a' + 'z' + 1;
            }
            ciphertext[i] = znak;
        }
        else if (znak >= 'A' && znak <= 'Z') {
            znak = znak - k;
            if (znak < 'A') {
                znak = znak - 'A' + 'Z' + 1;
            }
            ciphertext[i] = znak;
        }
    }
    printf("%s\n", ciphertext);
}

void caesar_bruteforce(char ciphertext[100]) {
	int k = 0;
	printf("odszyfrowane teksty z podanym kluczem:\n");
	while (k < 26){
		for (int i=0; ciphertext[i] != '\0'; i++) {
		    char znak;
		    znak = ciphertext[i];
		    if (znak >= 'a' && znak <= 'z'){
		        znak = znak - k;
		        if (znak < 'a'){
		            znak = znak - 'a' + 'z' + 1;
		        }
		        ciphertext[i] = znak;
		    }
		    else if (znak >= 'A' && znak <= 'Z') {
		        znak = znak - k;
		        if (znak < 'A') {
		            znak = znak - 'A' + 'Z' + 1;
		        }
		        ciphertext[i] = znak;
		    }
		}
		printf("klucz: %d, tekst: %s\n", k+1,ciphertext);
		k++;	
	}
}

int main() {
    
	printf("Wybierz jedna z opcji:\n");
	printf("1. Zaszyfruj tekst\n2. Odszyfruj tekst\n3. Bruteforce\n");
	int opcja;
	scanf("%d", &opcja);
	if (opcja == 1){
		char plaintext[100];
		int k;
		printf("Podaj tekst do zakodowania:\n");
		scanf("%s", &plaintext);
		printf("Podaj klucz:\n");
		scanf("%d", &k);
		caesar_encode(plaintext, k);
	}
	if (opcja == 2){
		char ciphertext[ROZMIAR];
		int k;
		printf("Podaj tekst do odszyfrowania\n");
		scanf("%s", &ciphertext);
		printf("Podaj klucz potrzebny do odszyfrowania\n");
		scanf("%d", &k);
		caesar_decode(ciphertext, k);
	}
	if (opcja == 3){
		char ciphertext[ROZMIAR];
		printf("Podaj tekst do odszyfrowania\n");
		scanf("%s", &ciphertext);
		caesar_bruteforce(ciphertext);
	}

    return 0;
}

