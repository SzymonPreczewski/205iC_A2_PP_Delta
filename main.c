#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b;
struct Delta {
    int a, b, c;
    float d, x0, x1, x2, p, q; //d to delta
};

void dane(struct Delta *dane) {
    printf("wprowadz a: ");
    scanf("%d",
          &dane->a);
    printf("wprowadz b: ");
    scanf("%d",
          &dane->b);
    printf("wprowadz c: ");
    scanf("%d",
          &dane->c);
    printf("a:%d b:%d c:%d\n",
           dane->a, dane->b, dane->c);
};


void rozwiazanie(struct Delta *dane) {
    if (dane->d > 0) {
        dane->x1 = (-dane->b + sqrt(dane->d)) / (2 * dane->a);
        dane->x2 = (-dane->b - sqrt(dane->d)) / (2 * dane->a);
        printf("x1 jest rowny: %f \nx2 jest równy: %f\n", dane->x1, dane->x2);
    } else if (dane->d == 0) {
        dane->x0 = (-dane->b) / (2 * dane->a);
        printf("x0 jest rowny: %f \n", dane->x0);
    } else {
        printf("Brak rozwiazan!!!\n");
    }
};

void delta(struct Delta *dane) {
    dane->d = pow(dane->b, 2) - (4 * dane->a * dane->c);
    printf("Delta jest rowna: %f\n", dane->d);
};


void wierzcholek(struct Delta *dane) {
    dane->p = (-dane->b) / (2 * dane->a);
    dane->q = (-dane->d) / (4 * dane->a);
    printf("Wspolrzedne wierzcholka:(%f;%f)\n", dane->p, dane->q);
};

void powrot() {
    printf("Ponowne uzycie programu 1\nBy zakonczyc prace programu wpisz cokolwiek\n");
    scanf("%d",
          &b);
    if (b == 1) {
        wczytaj();
    } else {
        return 0;
    }
};

void wczytaj() {
    struct delta *x = (struct Delta *) malloc(sizeof(struct Delta));
    dane(x);
    printf("Obliczenie delty: 1\n"
           "Miejsca zerowe: 2\n"
           "Wspolzedne wierzcholka: 3\n"
           "Wszytskie obliczenia: 4\n");
    scanf("%d",
          &a);
    if (a == 1) {
        delta(x);
        powrot();
    } else if (a == 2) {
        delta(x);
        rozwiazanie(x);
        powrot();
    } else if (a == 3) {
        delta(x);
        wierzcholek(x);
        powrot();
    } else {
        delta(x);
        rozwiazanie(x);
        wierzcholek(x);
        powrot();
    }
};

int main() {
    printf("W tym programie rozwiazesz rownania kwadratowe za pomoca delty.\n"
           "Podaj dane i wybierz co chcesz obliczyc.\n");
    wczytaj();
}