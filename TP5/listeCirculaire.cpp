#include <iostream>
#include "listeCirculaire.h"
using namespace std;


void initListeCirculaire(maillon **m){
    *m = NULL;
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
            cout << "Maillon " << (*tmp).numero << endl;
            tmp=(*tmp).suivant;
            if ((*p).suivant != p) {
                while (tmp != p) {
                    cout << "Maillon " << (*tmp).numero << endl;
                    tmp=(*tmp).suivant;
                }
            }
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

void insere(maillon **p, const int numero){
    maillon *m;
    maillon *prec;
    maillon *suivant;

    m = new maillon;
    (*m).numero = numero;

    if((*p) != NULL){
        prec = precedent((*p));cout << "precedent " << (*prec).numero << endl;
        suivant = (*p);cout << "suivant " << (*suivant).numero << endl;
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
    int nb;
    maillon *compteur;

    if (liste==NULL) {
        nb=0;
    } else {
        compteur=liste;
        nb++;
        while (compteur != precedent(liste)) {
            compteur=(*compteur).suivant;
            nb++;
        }
    }
    return nb;
}
