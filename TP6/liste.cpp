#include "liste.h"

void listeNouv(Liste ** liste){
    *liste = new Liste;
    initListe(*liste);
}

void initListe(Liste * liste){
    (*liste).tete = NULL;
    (*liste).fin = NULL;
}

void desinitListe(Liste * liste){
    while((*liste).tete != NULL){
        supprimerElementDebut(liste);
    }
}

void ajoueterElement(Liste * liste, element * e){
    element *tmp;

    (*e).suivant = NULL;
    if((*liste).tete == NULL){
        (*liste).tete = e;
        (*liste).fin = e;
    }else{
        tmp = (*liste).fin;
        (*tmp).suivant = e;
        (*liste).fin = e;
    }
}

void supprimerElementDebut(Liste * liste){
    element *e;

    if((*liste).tete != NULL){
        e = (*liste).tete;
        if((*e).suivant != NULL){
            (*liste).tete = (*e).suivant;
        }else{
            initListe(liste);
        }
        delete e;
    }
}

void concatenerListe(Liste * liste1, const Liste * liste2){
    element * finListe1;
    element * debutListe2;

    finListe1 = (*liste1).fin;
    debutListe2 = (*liste2).tete;

    if(finListe1 != NULL && debutListe2 != NULL){
        (*finListe1).suivant = debutListe2;
        (*liste1).fin = (*liste2).fin;
    }else if(debutListe2 == NULL && debutListe2 != NULL){
        (*liste1).tete = debutListe2;
        (*liste1).fin = (*liste2).fin;
    }

}

void afficherListe(const Liste liste){
    Liste tmp;
    element * e;
    tmp = liste;

    if(tmp.tete != NULL){
        e = tmp.tete;
        do{
            cout << (*e).caractere << " ";
            e = (*e).suivant;
        }while(e != NULL);
    }
    cout << endl;
}
