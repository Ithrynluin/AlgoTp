//fileAttente.cpp
//Implémentattion du module FileAttente
#include <iostream>
#include "fileAttente.h"
using namespace std;

/*
Procédure qui initialise une file
Paramètre de sortie: file d'attente initialisé
Post-condition: la tete et la queue dont égale à NULL
*/
void initFileAttente(FileAttente * file){
    (*file).tete = NULL;
    (*file).queu = NULL;
}

/*
Procédure qui supprimer tous les élèment de la file
Paramètre d'entrée: File d'attente à vider
Paramètre de sortie: File d'attente vide
Pré-condition: La file doit être initialiser
Post-condition: La file est vide et initialisé
*/
void desinitFileAttente(FileAttente *file){

    while((*file).tete != NULL){
        retireTete(file);
    }
}

/*
Procédure permettant d'ajouter une personne en queue de file d'attente
Paramètres d'entrée : file d'attente à laquelle on doit ajouter un maillon
                        numero de la personne à ajouer
                        nom de la personne
Paramètres de sortie : file d'attente avec le nouveau maillon en queue
Pré-condition : la file d'attente doit être initialisé
Post-conditon : le nouveau maillon est en queue de file.
*/
void ajoutPers (FileAttente * f, const int num, char * nom) {
    maillon * np;

    if((*f).tete == NULL) {
        np = new maillon;
        (*np).numero = num;
        (*np).nom = nom;
        (*np).suivant = NULL;

        (*f).tete = np;
        (*f).queu = np;
    } else {
        np = (*f).queu;
        (*np).suivant = new maillon;
        np = (*np).suivant;
        (*np).numero = num;
        (*np).nom = nom;
        (*np).suivant = NULL;
        (*f).queu = np;
    }
}
/*
Procédure qui retire une personne en queue de file
Paramètre entrée: file d'attente initialiser
Paramètre sortie: file d'attente avec un élément retiré en tete
Pré-condition: la file ne doit pas etre vide
Post-condition: le deuxième maillon est maintenant en tete
                  Si file ne contient qu'un éléemnt, le file est initialisée
*/
void retireTete(FileAttente * file){
    maillon * tmp;
    if((*file).tete == (*file).queu){
        tmp = (*file).tete;
        delete (*tmp).nom;
        delete tmp;
        initFileAttente(file);
    }else{
        tmp = (*file).tete;
        (*file).tete = (*tmp).suivant;
        delete tmp;
    }
}

/*
Procédure permettant de consulter la personne en tete de file
Paramètre entrée : file d'attente initialisée
Paramètre sortie : affichage de la personne en tete
Pré-condition : la file doit être initialisée
*/
void consulterTete (FileAttente file) {
    if(file.tete != NULL){
        cout << "La tete de file est : " << (*file.tete).nom << " qui possede le numero " << (*file.tete).numero << endl;
    }else{
        cout << "Personne dans la liste" << endl;
    }

}

/*
Fonction qui retourne la taille de la file
Paramètre d'entrée: la file d'attente
Retourne: la longueur de la file d'attente
Pré-condition: la file doit être initialisé
*/

int longueurFile(const FileAttente file){
    int lg = 0;
    maillon * p = file.tete;

    while(p != NULL){
        lg++;
        p = (*p).suivant;
    }

    return lg;
}


