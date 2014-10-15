#ifndef LISTECIRCULAIRE_H_INCLUDED
#define LISTECIRCULAIRE_H_INCLUDED

typedef struct m {
    int numero;
    m * suivant;
} maillon;

void initListeCirculaire(maillon **m);
void afficherListe(maillon *p);
maillon * precedent(maillon *p);
void rotation(maillon **pp);
void insere(maillon **p, const int numero);
int nombreMaillons(maillon *liste);


#endif // LISTECIRCULAIRE_H_INCLUDED
