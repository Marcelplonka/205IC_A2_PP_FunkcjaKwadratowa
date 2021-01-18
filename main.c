#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Punkt {
    float x, y;
};

struct FunkcjaKwadratowa {
    int a, b, c;
    int delta;
    float x1, x2, x0;
    struct Punkt wierzcholek;
};

struct FunkcjaKwadratowa *WczytajDane();

void WypiszDane(struct FunkcjaKwadratowa *F);

void ZnajdzDelte();

void ZnajdzMS();

void ZnajdzW();

int main() {

    struct FunkcjaKwadratowa *MojaFunkcja = WczytajDane();
    ZnajdzDelte(MojaFunkcja);
    ZnajdzMS(MojaFunkcja);
    ZnajdzW(MojaFunkcja);
    WypiszDane(MojaFunkcja);

    return 0;
}

struct FunkcjaKwadratowa *WczytajDane() {
    struct FunkcjaKwadratowa *MojaFunkcja = (struct MojaFunkcja *)
            malloc(sizeof(struct FunkcjaKwadratowa));
    scanf("%d %d %d", &(MojaFunkcja->a), &(MojaFunkcja->b), &(MojaFunkcja->c));
    if (MojaFunkcja->a == 0) {
        printf("Funkcja jest liniowa.");

        return 0;
    } else
        return MojaFunkcja;

};

void WypiszDane(struct FunkcjaKwadratowa *F) {

    if ((F->a) == 1) {
        printf("\n f(x) = x^2 + %dx + %d", F->b, F->c);
    } else if ((F->a) == -1) {
        printf("\n f(x) = -x^2 + %dx + %d", F->b, F->c);
    } else {
        printf("\n f(x) = %dx^2 + %dx + %d", F->a, F->b, F->c);
    }

    printf("\n Delta = %d\n", F->delta);
    if ((F->delta) < 0) {
        printf("Brak miejsc zerowych");
    } else if ((F->delta) == 0) {
        printf("x0 = %.2f", F->x0);
    } else {
        printf("x1 = %.2f\n x2 = %.2f", F->x1, F->x2);
    }
    printf("\nW = (%.2f, %.2f)", F->wierzcholek.x, F->wierzcholek.y);

}

void ZnajdzDelte(struct FunkcjaKwadratowa *F) {

    (F->delta) = pow(F->b, 2) - 4 * (F->a) * (F->c);
}

void ZnajdzMS(struct FunkcjaKwadratowa *F) {

    if ((F->delta) == 0) {
        F->x0 = (-F->b) / (2 * F->a);
    } else
        F->x1 = (float) (-F->b - sqrt(F->delta)) / (2 * F->a);
    F->x2 = (float) (-F->b + sqrt(F->delta)) / (2 * F->a);
}

void ZnajdzW(struct FunkcjaKwadratowa *F) {

    F->wierzcholek.x = (float) (-F->b / 2 * (F->a));
    F->wierzcholek.y = (float) (-F->delta / 4 * (F->a));
}