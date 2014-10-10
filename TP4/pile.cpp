#include <iostream>
#include <cstring>
#include "pile.h"


using namespace std;

/*
 Fonction qui initialise une pile
 Para*/
Pile initPile(Pile pile){
    pile.tete = NULL;
}

void empiler(Pile &pile, FileAttente *file){

    element e;
    e.file = (*file);
    if(pile.tete != NULL){
        e.suivant = pile.tete;
    }else{
        e.suivant = NULL;
    }
    pile.tete = &e;
}

element sommet(Pile pile){
    return (*pile.tete);
}

void desinitPile(Pile &pile){

  while(pile.tete != NULL){
      depiler(pile);
  }
}

void depiler(Pile &pile){
    element *tmp;

    if(pile.tete != NULL) {
        tmp=pile.tete;
        if ((*pile.tete).suivant == NULL) {
            desinitFileAttente((*tmp).file);
            delete tmp;
            initPile(pile);
        } else {
            desinitFileAttente((*tmp).file);
            pile.tete=(*tmp).suivant;
            delete tmp;
        }
    }
}

FileAttente copier(FileAttente file){
    FileAttente nf;
    maillon *np = file.tete;
    maillon maille;
    initFileAttente(nf);

    while(np != NULL){
        maille.numero = (*np).numero;
        strncpy(maille.nom, (*np).nom, 30);
        maille.suivant = NULL;
        ajoutPers(nf, &maille);
        np = (*np).suivant;
    }

    return nf;
}
