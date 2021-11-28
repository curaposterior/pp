#include <stdio.h>
#include <string.h>

#define MAX_DL 50
#define PRAWDA 1
#define FALSZ 0

void czy_palindrom(char str[]);

int main() {
	char str[50];
	printf("Podaj slowo do sprawdzenia: \n");
	for (int i=0; i < 5; i++){
		scanf("%s", str);
		czy_palindrom(str);
	}
}

void czy_palindrom(char str[]) {
	int dl = strlen(str);
	int flag = PRAWDA;
	for (int i = 0; i < dl; i++){
		if (str[i] != str[dl - 1 - i]){
			printf("podane slowo nie jest palindromem\n");
			flag = FALSZ;
			break;
		}
	}
	if (flag)
		printf("podane slowo jest palindromem\n");
}