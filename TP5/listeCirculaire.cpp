#include <iostream>
#include "listeCirculaire.h"
using namespace std;

/*
Procédure qui initialise une liste
Paramètre de sortie: liste initialisée
Post-condition: le pointeur pointe sur rien
*/
void initListeCirculaire(maillon **m){
    *m = NULL;
}
/*
Procédure qui supprimer tous les élèment de la liste
Paramètre d'entrée: liste à vider
Paramètre de sortie: liste vide
Pré-condition: La liste doit être initialisée
Post-condition: La liste est vide
*/
void desinitListeCirculaire(maillon **m){
    while (*m != NULL) {
            supprime(m);
    }
}

/*
Procédure permettant l'affichage d'une liste circulaire
Paramètre entrée: liste initialisée
Paramètre sortie: affichage de la liste
Pré-condition: la liste ne doit pas etre vide
*/
void afficherListe(maillon *p) {
        maillon *tmp;

        if (p != NULL) {
            tmp=p;
            do{
                cout << "Maillon " << (*tmp).numero << endl;
                rotation(&tmp);
            }while(tmp != p);

        }
}
/*
Fonction permettant d'accéder au maillon précédent celui qui est point" en entrée
Paramètre entrée : liste initialisée
Paramètre sortie : retourne le maillon précédent
Pré-condition : la liste doit etre initialisée
*/
maillon * precedent(maillon *p) {
    maillon *tmp;

    tmp=p;
    if (p != NULL) {
        while ((*tmp).suivant != p) {
            tmp=(*tmp).suivant;
        }
    }
    return tmp;
}
/*
Procédure pour effectuer une rotation dans la liste
Paramètre entrée : liste initialisée
Paramètre sortie : liste ayant subi la rotation
Pré-condition : la liste doit etre initialisée et non nulle
Post-condition : la liste a subi une rotation
*/
void rotation(maillon **pp) {
    (*pp) = (**pp).suivant;
}
/*
Procédure permettant d'ajouter un maillon dans la liste
Paramètres d'entrée : liste à laquelle on souhaite ajouter un maillon
                        numero du maillon à ajouter
Paramètres de sortie : liste pointant vers le maillon ajouté
Pré-condition : la liste doit être initialisée
Post-conditon : le nouveau maillon est le premier maillon pointé par la liste
*/
void insere(maillon **p, const int numero){
    maillon *m;
    maillon *prec;
    maillon *suivant;

    m = new maillon;
    (*m).numero = numero;

    if((*p) != NULL){
        prec = precedent((*p));
        suivant = (*p);
        (*m).suivant = suivant;
        (*prec).suivant = m;
    }else{
        (*m).suivant = m;
    }
    *p = m;
}
/*
Fonction permettant de connaitre le nombre de maillon contenu dans la liste
Paramètre d'entrée : liste initialisée
Paramètre de sortie : retourne le nombre de maillons de la liste
Pré-condition : la liste doit etre initialisée
*/
int nombreMaillons(maillon *liste) {
    int nb = 0;
    maillon *compteur;

    if (liste==NULL) {
        nb=0;
    } else {
        compteur=liste;
        do{
            nb++;
            rotation(&compteur);
        }while(compteur != liste);
    }
    return nb;
}
/*
Procédure qui retire le maillon de la liste pointé par p
Paramètre entrée: liste initialisée
Paramètre sortie: liste avec le maillon retiré
Pré-condition: la liste ne doit pas etre vide
Post-condition: si la liste ne contient plus de maillon, elle est initialisée
*/
void supprime(maillon **p){
    maillon * pre;
    maillon * suiv;

    if(*p != NULL){
        suiv = (**p).suivant;
        if(*p == suiv){
            delete *p;
            initListeCirculaire(p);
        }else{
            pre = precedent(*p);
            delete *p;
            *p = pre;
            (**p).suivant = suiv;
        }
    }
}
