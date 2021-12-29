#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct book{
    char name[35];
    char author[30];
    int id;
    double rating;
    struct book *next;
};

struct book *start_lib=NULL;
struct book *initialize_lib(struct book *start);
void display(struct book *start);
struct book *add_book(char bookname[30],char authorname[30],int id, double rating);
struct book *delete_book(int id);
void sort_books(struct book **pphead);
void search(struct book* start_lib, int id);
void main_menu();

int main() {
    start_lib=initialize_lib(start_lib);
    main_menu();
    return 0;
}

void main_menu(){
    int choice;
    do {
        printf("\n      MAIN MENU: ");
        printf("\n\t1. Dodaj ksiazke. ");
        printf("\n\t2. Usun ksiazke.");
        printf("\n\t3. Posortuj ksiazki w bibliotece (wg tytulu).");
        printf("\n\t4. Wyswietl biblioteke.");
        printf("\n\t5. Wyswietl ksiazke.");
        printf("\n\t6. Wyjscie z programu.");
        printf("\n\tWybierz opcje: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                char nazwa[30];
                char autor[30];
                char temp;
                int id;
                double ocena;
                printf("\n\tPodaj dane do dodania ksiazki:\n");
                scanf("%c", &temp);
                printf("Tytul: ");
                scanf("%[^\n]", nazwa);
                scanf("%c", &temp);
                printf("Autor: ");
                scanf("%[^\n]", autor);

                scanf("%c", &temp);
                printf("ID ksiazki: ");
                scanf("%d", &id);
                printf("Ocena: ");
                scanf("%lf", &ocena);
                printf("\n");
                
                start_lib = add_book(nazwa, autor, id, ocena);
                break;
            }
            case 2:{
                int id_del;
                printf("\nPodaj id ksiazki ktora chcesz usunac:\n");
                scanf("%d", &id_del);
                start_lib = delete_book(id_del);
                break;
            }
            case 3:{
                struct book** data = &start_lib;
                sort_books(data);
                break;
            }
            case 4:{
                display(start_lib);
                break;
            }
            case 5:{
                int op5;
                printf("Podaj ID ksiazki do wyswietlenia:\n");
                scanf("%d", &op5);
                search(start_lib, op5);
                break;
            }
            case 6: {
                exit(1);
            }
            default:{
                printf("\n\tZla opcja\n");
                printf("\n\tWybierz ponownie: ");
                getch();
            }
        }
    } while (choice!=6);
}

struct book *initialize_lib(struct book *start){
    struct book *ptr,*new_book;

    new_book=(struct book *)malloc(sizeof(struct book));

    new_book->next=NULL;

    start_lib=new_book;

    strcpy(new_book->name, "Wladca Pierscieni - Dwie Wieze");
    strcpy(new_book->author,"J.R.R Tolkien");

    new_book->id=101;
    new_book->rating=10.0;

    return start_lib;
}

void display(struct book *start) {
    struct book *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("Wyswietlanie informacji o ksiazkce:\n");
        printf("\nname: %s",ptr->name);
        printf("\nAutor: %s",ptr->author);
        printf("\nID: %d",ptr->id);
        printf("\nOcena: %lf",ptr->rating);
        printf("\n*************************************************\n");
        ptr=ptr->next;
    }
    printf("\nNacisnij jakis przycisk zeby powrocic do menu: \n");
    getch();
    system("cls");
}

struct book *delete_book(int id){
    struct book *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while (ptr!=NULL) {
        c++;
        ptr=ptr->next;
    }
    if (c==1) {
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }
    else if (start_lib->id==id) {
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }
    else {
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],int id, double rating){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));

    strcpy(new_book->name, bookname);
    strcpy(new_book->author, authorname);

    new_book->id = id;
    new_book->rating = rating;
    new_book->next = NULL;

    if(start_lib == NULL) {
        start_lib = new_book;
    }
    else {
        ptr=start_lib;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_book;
    }
    return start_lib;
}

//dzięki Wojtek za funkcję sortującą
void sort_books(struct book **pphead) {
    printf("Sortuje ksiazki...\n");

    struct book* p_book = *pphead;
    struct book* p_PrevBook = NULL;
    struct book* p_tmp1 = NULL;
    struct book* p_tmp2 = NULL;

    if (p_book == NULL) {
        printf("Nie ma nic do sortowania\n");
    }
    else
    {
        bool change =  false;
        do {
            change = false;
            p_book = *pphead;
            p_PrevBook = NULL;
            do {
                if (p_book->next != NULL) {
                    if (strcmp(p_book->name, (p_book->next)->name) < 0) {
                        if (p_PrevBook != NULL)
                            p_PrevBook->next = p_book->next; 
                        else 
                            *pphead = p_book->next;

                        p_tmp1 = (p_book->next)->next;
                        p_tmp2 = p_book->next;
                        (p_book->next)->next = p_book;
                        p_book->next = p_tmp1;
                        p_book = p_tmp2; 

                        change = true;
                    }
                }
                p_PrevBook = p_book;
                p_book = p_book->next;
            }
            while (p_book !=NULL);
        }
        while (change);
    }
    printf("\nNacisnij jakis przycisk zeby powrocic do menu: \n");
    getch();
    system("cls");
}

void search(struct book* start_lib, int id) {
    struct book* ptr;
    ptr = start_lib;
    while (ptr!=NULL) {
        if (ptr->id == id) {
            printf("\nWyswietlanie informacji o ksiazkce:\n");
            printf("*************************************************");
            printf("\nname: %s",ptr->name);
            printf("\nAutor: %s",ptr->author);
            printf("\nID: %d",ptr->id);
            printf("\nOcena: %lf",ptr->rating);
            printf("\n*************************************************\n");
        }
        ptr = ptr->next;
    }
    printf("\nNacisnij jakis przycisk zeby powrocic do menu: \n");
    getch();
    system("cls");
}
