#ifndef LISTECIRCULAIRE_H_INCLUDED
#define LISTECIRCULAIRE_H_INCLUDED

typedef struct m {
    int numero;
    m * suivant;
} maillon;

/*
Procédure qui initialise une liste
Paramètre de sortie: liste initialisée
Post-condition: le pointeur pointe sur rien
*/
void initListeCirculaire(maillon **m);
/*
Procédure qui supprimer tous les élèment de la liste
Paramètre d'entrée: liste à vider
Paramètre de sortie: liste vide
Pré-condition: La liste doit être initialisée
Post-condition: La liste est vide
*/
void desinitListeCirculaire(maillon **m);
/*
Procédure permettant l'affichage d'une liste circulaire
Paramètre entrée: liste initialisée
Paramètre sortie: affichage de la liste
Pré-condition: la liste ne doit pas etre vide
*/
void afficherListe(maillon *p);
/*
Fonction permettant d'accéder au maillon précédent celui qui est point" en entrée
Paramètre entrée : liste initialisée
Paramètre sortie : retourne le maillon précédent
Pré-condition : la liste doit etre initialisée
*/
maillon * precedent(maillon *p);
/*
Procédure pour effectuer une rotation dans la liste
Paramètre entrée : liste initialisée
Paramètre sortie : liste ayant subi la rotation
Pré-condition : la liste doit etre initialisée et non nulle
Post-condition : la liste a subi une rotation
*/
void rotation(maillon **pp);
/*
Procédure permettant d'ajouter un maillon dans la liste
Paramètres d'entrée : liste à laquelle on souhaite ajouter un maillon
                        numero du maillon à ajouter
Paramètres de sortie : liste pointant vers le maillon ajouté
Pré-condition : la liste doit être initialisée
Post-conditon : le nouveau maillon est le premier maillon pointé par la liste
*/
void insere(maillon **p, const int numero);
/*
Fonction permettant de connaitre le nombre de maillon contenu dans la liste
Paramètre d'entrée : liste initialisée
Paramètre de sortie : retourne le nombre de maillons de la liste
Pré-condition : la liste doit etre initialisée
*/
int nombreMaillons(maillon *liste);
/*
Procédure qui retire le maillon de la liste pointé par p
Paramètre entrée: liste initialisée
Paramètre sortie: liste avec le maillon retiré
Pré-condition: la liste ne doit pas etre vide
Post-condition: si la liste ne contient plus de maillon, elle est initialisée
*/
void supprime(maillon **p);


#endif // LISTECIRCULAIRE_H_INCLUDED
