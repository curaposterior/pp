#include <stdio.h>
#include <math.h>

struct Okrag
{
    int x,y,promien;
};

int czyNalezyDoOkregu(int x, int y, int r, int x_1, int y_1)
{
    int rownanie;
    rownanie = pow(x_1 - x, 2) + pow(y_1 - y, 2);
    if (rownanie > pow(r, 2) || rownanie == pow(r, 2)) {
        // printf("punkt nie lezy wewnatrz okregu\n");
        return 2;
    }
    if (rownanie < pow(r, 2))
        return 3; 
}

int main(void)
{
    struct Okrag o1 = {0, 0, 2};
    struct Okrag o2 = {3, 1, 5};
    struct Okrag o3 = {6, 4, 2};

    int x_1, y_1;
    printf("Podaj wspolrzedne punktu:\n");
    scanf(" %d %d", &x_1, &y_1);
    
    if (czyNalezyDoOkregu(o1.x,o1.y, o1.promien, x_1,  y_1) == 3)
        printf("Punkt lezy wewnatrz okregu 1\n");
    
    if (czyNalezyDoOkregu(o2.x, o2.y, o2.promien, x_1, y_1) == 3)
        printf("Punkt lezy wewnatrz okregu 2\n");
    
    if (czyNalezyDoOkregu(o3.x, o3.y, o3.promien, x_1, y_1) == 3)
        printf("Punkt lezy wewnatrz okregu 3\n");
}