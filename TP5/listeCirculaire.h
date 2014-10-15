#ifndef LISTECIRCULAIRE_H_INCLUDED
#define LISTECIRCULAIRE_H_INCLUDED

typedef struct m {
    int numero;
    m * suivant;
} maillon;

void initListeCirculaire(maillon **m);


#endif // LISTECIRCULAIRE_H_INCLUDED
