#ifndef LISTECIRCULAIRE_H_INCLUDED
#define LISTECIRCULAIRE_H_INCLUDED

typedef struct m {
    int numero;
    m * suivant;
} maillon;

void initListeCirculaire(maillon **m);
void afficherListe(maillon *p)


#endif // LISTECIRCULAIRE_H_INCLUDED
