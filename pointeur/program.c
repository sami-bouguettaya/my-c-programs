#include <stdio.h>

typedef struct {
    int heure;
    int minute;
    int seconde;
} TEMPS;

TEMPS somme_temps(TEMPS T1, TEMPS T2) {
    TEMPS T;
   T.heure = T1.heure + T2.heure;
   T.minute = T1.minute + T2.minute;
   T.seconde  = T1.seconde + T2.seconde;
 return T;
}

int transform(TEMPS T) {
    int total_secondes = T.heure * 3600 + T.minute * 60 + T.seconde;
    return total_secondes;
}

// Procédure qui décompose un temps exprimé en secondes en un temps T de type TEMPS
void decompos(int S, TEMPS* T) {
    T->heure = S / 3600;
    T->minute = (S % 3600) / 60;
    T->seconde = (S % 3600) % 60;
}

int main() {
    TEMPS T1 = {2, 10, 37}; // T1 = 2 heures 10 minutes 37 secondes
    TEMPS T2 = {1, 20, 45}; // T2 = 1 heure 20 minutes 45 secondes
    
    TEMPS T = somme_temps(T1, T2); // Calculer la somme de T1 et T2
    printf("La somme de T1 et T2 est: %d heures %d minutes %d secondes\n", T.heure, T.minute, T.seconde);
    
    int S = transform(T); // Transformer T en un entier S
    printf("Le temps T exprimé en secondes est: %d secondes\n", S);
    
    TEMPS T3; // Décomposer S en un temps T3
    decompos(S, &T3);
    printf("Le temps T3 est: %d heures %d minutes %d secondes\n", T3.heure, T3.minute, T3.seconde);
    
    return 0;
}