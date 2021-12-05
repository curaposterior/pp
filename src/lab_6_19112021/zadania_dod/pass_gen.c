//Zadania przygotowane na podstawie instrukcji z zajec

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define STR_SIZE 50

void validation(char genPass[]) {
    char pass[STR_SIZE];
    int length = strlen(genPass), flag = 1;
    printf("Wczytaj haslo\n");
    scanf("%s", pass);
    for (int i=0; i < length; i++) {
        if (pass[i] != genPass[i]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("hasla sa takie same");
    }
    else
        printf("hasla sa rozne");
}

int generateRandomNumbers() {
    int random;
    random = (rand() % (125 + 1 - 33)) + 33;
}

int main() {
    srand(time(NULL));
    
    int passLen, randNum, ver;
    char genPass[STR_SIZE];
    char* pass;

    printf("Podaj dlugosc hasla:\n");
    scanf("%d", &passLen);
    for (int i=0; i < passLen; i++){
        randNum = generateRandomNumbers();
        genPass[i] = randNum;
    }
    printf("%s\n", genPass);

    printf("Czy chcesz zweryfikowac swoje haslo?\n1. Tak\n2. Nie\n");
    scanf("%d", &ver);

    switch (ver)
    {
    case 1:
        validation(genPass);
        break;

    case 2:
        return 0;
    
    default:
        printf("...");
        break;
    }
    return 0;
}