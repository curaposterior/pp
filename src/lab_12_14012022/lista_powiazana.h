#ifndef LISTA_POWIAZANA_H
#define LISTA_POWIAZANA_H

typedef struct element_listy* wsk_el_list;

typedef struct element_listy{
  char* nazwa_wezla;
  int klucz;
  wsk_el_list nastepny_wezel; // wskaźnik do kolejnego elementu
} el_list;

int wstaw_na_poczatek( el_list** Glowa_wsk, el_list* Element_wsk);
void drukuj_lista(el_list* Glowa);
int usun_lista(el_list** Glowa_wsk, el_list* Element_wsk);
void drukuj_lista(el_list* Glowa);
el_list* wyszukaj_lista(el_list* Glowa, int klucz);
#endif
