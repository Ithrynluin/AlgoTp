#include <iostream>
#include <cstring>
#include "pile.h"

using namespace std;

/*
Procédure qui initialise une pile
Paramètre d'entrée : pile non initialisée
Paramètre de sortie: pile initialisée
Post-condition: la tete et la queue de la pile doit etre égale à NULL
*/
void initPile(Pile &pile){
    pile.tete = NULL;
}
/*
Procédure qui supprimer tous les élèment de la pile
Paramètre d'entrée: Pile à vider
Paramètre de sortie: Pile vide
Pré-condition: La pile doit être initialisée
Post-condition: La pile est vide et initialisée
*/
void desinitPile(Pile &pile){
    while(pile.tete != NULL){
        depiler(pile);
    }
}
/*
Procédure permettant d'ajouter une file d'attente en tete de la pile
Paramètres d'entrée : pile où l'on souhaite ajouter l'élément
Paramètres de sortie : pile avec le nouvel élément en tete
Pré-condition : la pile doit être initialisée
Post-conditon : le nouvel élément est en tete de la pile
*/
void empiler(Pile &pile, FileAttente *file){
    element *e = new element;
    element *tmp;
    (*e).file = file;
    (*e).suivant = NULL;
    if(pile.tete != NULL){
        tmp = pile.tete;
        (*e).suivant = tmp;
    }
    pile.tete = e;
}
/*
Procédure qui retire la file d'attente en tete de la pile
Paramètre entrée: pile initialisée
Paramètre sortie: pile avec un élément retiré en tete
Pré-condition: la pile ne doit pas etre vide
Post-condition: le deuxième élément est maintenant en tete
*/
void depiler(Pile &pile){
    FileAttente *file;
    element *e, *tmp;

    if(pile.tete != NULL){
        e = pile.tete;
        file = (*e).file;
        if((*e).suivant == NULL){
            pile.tete = NULL;
        }else{
            tmp = (*e).suivant;
            pile.tete = tmp;
        }
    }
}
/*
Fonction permettant de consulter la file d'attente en tete de la pile
Paramètre entrée : pile initialisée
Paramètre sortie : retourne la file d'attente en tete de la pile
Pré-condition : la pile doit être initialisée
Post-condition : retourne l'élement de tete ou NULL si la pile est vide
*/
element * sommet(Pile pile){
    return pile.tete;
}
/*
Procédure permettant d'enregistrer une file en l'état actuel de l'enregistrement dans la pile
Paramètre entrée : une pile initialisée et une file d'attente initialisée
Paramètre sortie : la file d'attente est copiée dans la pile
Pré-condition : la pile et la file doivent être initialisées
Post-condition :la pile avec une copie de la file d'attente en tete
*/
void enregistreEtat(Pile &pile, const FileAttente file){
    FileAttente *fileCopie;

    fileCopie = copierFileAttente(file);
    empiler(pile, fileCopie);
}
/*
Procédure d'annuler la dernière action effectuée sur une file d'attente
Paramètre entrée : pile initialisée et file d'attente initialisée
Paramètre sortie : la file d'attente se retrouve dans son état précédent
Pré-condition : la pile et la file est initialisée
Post-condition : le dernier état de la file est supprimée
*/
void undo(Pile &pile, FileAttente &file){
    element *e;

    desinitFileAttente(file);
    e = sommet(pile);
    file = (*(*e).file);
    depiler(pile);
}
/*
Fonction permettant de copier une file d'attente
Paramètre entrée : file d'attente initialisée
Paramètre sortie : copie de la file d'attente
Pré-condition : la file doit être initialisée
Post-condition : retourne un pointeur une coupie de la file
*/
FileAttente* copierFileAttente(const FileAttente source){
    FileAttente *destination = new FileAttente;
    char nom[30];
    int numero;
    maillon *maille = source.tete;
    initFileAttente(*destination);
    while(maille != NULL){
        numero = (*maille).numero;
        strncpy(nom, (*maille).nom, 30);
        ajoutPers(*destination, numero, nom);
        maille = (*maille).suivant;
    }
    return destination;
}
/*
Fonction qui retourne la taille de la pile
Paramètre d'entrée: pile initialisée
Retourne: la longueur de la pile
Pré-condition: la pile doit être initialisée
*/
int longueurPile(Pile pile){
    element *e;
    e = pile.tete;
    int l = 0;

    while(e != NULL){
        l++;
        e = (*e).suivant;
    }
    return l;
}
