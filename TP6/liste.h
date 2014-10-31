#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct car {
    char caractere;
    struct car *suivant;
} element;

typedef struct {
    element * tete;
    element * fin;
}Liste;

void listeNouv(Liste ** liste);
/*
Initialise la liste
Paramètre d'entrée : une liste non initialisée
Paramètre de sortie : une liste initialisé
*/
void initListe(Liste *liste);
/*
Détruit le contenu de la liste et l'initialise
Paramètre d'entrée : Une liste initialisé.
Paramètre de sortie : Une liste vide et initialisé.
Pré-condition : la liste doit être initialisé.
Post-condition : le contenu de la liste est détruit.
*/
void desinitListe(Liste * liste);
/*
Ajoute un élément en fin de liste.
Paramètre d'entrée :    une liste
                        l'élément à ajouetr.
Paramètre de sortie : la liste avec le nouvelle élément.
Pré-condition : la liste doit être initialisé
*/
void ajoueterElement(Liste * liste, element * e);
/*
Supprime le premier élément la liste.
Paramètre d'entrée : une liste
Paramètre de sortie : la lsite avec le premier instrument détruit
Pré-condition : la liste doit être initialisé
Post-condition : la liste est initialisé s'il n'y a plus d'élément
*/
void supprimerElementDebut(Liste * liste);
/*
Concatène deux liste.
Paramètre d'entrée : 2 listes à concaténer
Paramètre de sortie : la liste concaténer
Pré-condition : les listes doivent être initialisées.
*/
void concatenerListe(Liste * liste1, const Liste * liste2);
/*
Affiche une liste de caractère.
Paramètre d'entrée : une liste
Pré-condition : la liste doit être initialisée.
*/
void afficherListe(const Liste liste);

#endif // LISTE_H_INCLUDED
