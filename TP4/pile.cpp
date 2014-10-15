#include <iostream>
#include <cstring>
#include "pile.h"

using namespace std;

void initPile(Pile &pile){
    pile.tete = NULL;
}

void desinitPile(Pile &pile){
    while(pile.tete != NULL){
        depiler(pile);
    }
}

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

void depiler(Pile &pile){
    FileAttente *file;
    element *e, *tmp;

    if(pile.tete != NULL){
        e = pile.tete;
        file = (*e).file;
 //       desinitFileAttente(*file);
     //   delete file;
        if((*e).suivant == NULL){
            pile.tete = NULL;
        }else{
            tmp = (*e).suivant;
            pile.tete = tmp;
        }
    }
}

element * sommet(Pile pile){
    return pile.tete;
}

void enregistreEtat(Pile &pile, const FileAttente file){
    FileAttente *fileCopie;

    fileCopie = copierFileAttente(file);
    empiler(pile, fileCopie);
}

void undo(Pile &pile, FileAttente &file){
    element *e;

    desinitFileAttente(file);
    e = sommet(pile);
    file = (*(*e).file);
    depiler(pile);
}

/*void copierFileAttente(const FileAttente source, FileAttente &destination){
    char nom[30];
    int numero;
    maillon *maille = source.tete;
    initFileAttente(destination);
    while(maille != NULL){
        numero = (*maille).numero;
        strncpy(nom, (*maille).nom, 30);
        ajoutPers(destination, numero, nom);
        maille = (*maille).suivant;
    }
}*/

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
