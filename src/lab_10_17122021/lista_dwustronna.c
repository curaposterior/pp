#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// lista dwukierunkowa na danych typu int
/*
TODO:
- naprawic wypisywanie od tylu
*/

typedef struct ListElem {
    int data;
    struct ListElem* previous;
    struct ListElem* next;
} ListElemType;

void wypisz(ListElemType* head);
void wypiszOdTylu(ListElemType* head);
void dodajNaPoczatku(ListElemType** head, int num);
void dodajNaKoncu(ListElemType** head, int num);
void menu(void);

int main(void) {
    
    ListElemType* head = NULL;
    head = (ListElemType *)malloc(sizeof(ListElemType));
    head = NULL;
    
    int option, number, i;

    while (true) {
        // system("cls");
        printf("Wybierz opcje: \n");
        menu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nWypisywanie liczb:\n");
            wypisz(head);
            break;
        
        case 2:
            printf("\nWypisywanie liczb od tylu:\n");
            wypiszOdTylu(head);
            break;

        case 3:
            printf("Wpisz liczbe jaka chcesz dodac do listy:\n");
            scanf("%d", &number);
            dodajNaPoczatku(&head, number);
            break;

        case 4:
            printf("Wpisz liczbe jaka chcesz dodac do listy:\n");
            scanf("%d", &number);
            dodajNaKoncu(&head, number);
            break;

        case 5:
            return 0;
            break;
        }
    }
    return 0;
}

void menu() {
    printf("1. Wypisz liste\n");
    printf("2. Wypisz liste od tylu\n");
    printf("3. Dodaj liczbe na poczatku\n");
    printf("4. Dodaj liczbe na koncu\n");
    printf("5. Wyjdz z programu\n");
}

void wypisz(ListElemType* head) {
    printf("\n");
    if (head == NULL)
        printf("Lista jest pusta\n");
    else {
        ListElemType* current = head;
        do {
            printf("%d\n", current->data);
            current = current->next;
        } while (current != NULL);
    }
}

//jeszcze nie dziala
void wypiszOdTylu(ListElemType* head) {
    printf("\n");
    if (head == NULL)
        printf("Lista jest pusta\n");
    else {
        ListElemType* current = head;
        while (current->next != NULL) {
            current = current->next; //przechodzimy na koniec listy
        }
        do {
            printf("%i", current->data);
            printf("\n");
            current = current->previous;
        }while (current != NULL);
    }
}

void dodajNaPoczatku(ListElemType** head, int num) {
    ListElemType* current = NULL;
    current = (ListElemType*)malloc(sizeof(ListElemType)); //przypisujemy miejsce w pamieci nowemu elementowi

    current->data = num; //tworzymy tymczasowy obiekt curent w ktorym przechowujemy nowe wartosci
    current->next = (*head);
    *head = current;
}

void dodajNaKoncu(ListElemType** head, int num) {
    if (*head == NULL) {
        *head = (ListElemType*)malloc(sizeof(ListElemType));
        (*head) -> data = num;
        (*head) -> next = NULL;
    }
    else {
        ListElemType* current = *head;

        while (current -> next != NULL)
            current = current -> next;

        current->next = (ListElemType*)malloc(sizeof(ListElemType));
        current->next->data = num;
        current->next->next = NULL;
    }
}