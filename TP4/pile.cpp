#include <iostream>
#include "pile.h"


using namespace std;

/*
 Fonction qui initialise une pile
 Para
Pile initPile(Pile pile){
    pile.tete = NULL;
}

void empliler(Pile &pile, FileAttente file){

    element e;
    e.file = file;
    if(pile.tete != NULL){
        e.suivant = pile.tete;
    }else{
        e.suisvant = NULL
    }
    pile.tete = &e;
}

element sommet(Pile pile){
    return pile.tete;
}
