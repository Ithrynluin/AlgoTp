#include "arbre.h"


/*
Procédure qui initialise un arbre
Paramètre de sortie: arbre initialisé
Post-condition: le pointeur (abin) pointe sur rien
*/
void arbnouv (abin a) {
    a = NULL;
}
/*
Procédure qui supprimer tous les élèment de l'arbre
Paramètre d'entrée: arbre à détruire
Paramètre de sortie: arbre détruit
Pré-condition: L'arbre doit être initialisé
Post-condition: L'arbre est détruit
*/
void arbdetruit (abin a) {
    if(a != NULL) {
        arbdetruit((*a).ag);
        arbdetruit((*a).ad);
        delete (a);
    }
}

/*
Fonction qui renvoie l'élément à gauche du noeud choisi
Paramètre d'entrée : pointeur de noeud (abin)
Paramètre de sortie : noeud à gauche de celui choisi dans l'arbre
Pré-condition : L'arbre doit être initialisé
*/
noeud gauche (abin a) {
    if (a != NULL) {
        return (*a).ag;
    } else {
        return NULL;
    }
}
/*
Fonction qui renvoie l'élément à droite du noeud choisi
Paramètre d'entrée : pointeur de noeud (abin)
Paramètre de sortie : noeud à droite de celui choisi dans l'arbre
Pré-condition : L'arbre doit être initialisé
*/
noeud droite (abin a) {
    if(a != NULL) {
        return (*a).ad;
    } else {
        return NULL;
    }

/*
Fonction qui permet la création d'une racine entre deux arbres
Paramètres d'entrée : nom de la racine (en un seul caractère), et les deux arbres à enraciner
Paramètre de sortie un noguvel arbre rassemblant les deux arbres en paramètre
Pré-condition : les arbres ne doivent pas être vides
*/
abin enracine(const char etiq, abin ag, abin ad){
    abin a;

    (*a).etiquette = etiq;
    (*a).ag = ag;
    (*a).ad = ad;
    return a;
}

/*Fonction estVide (ab : ArbreBin) retourne booléen
Début
	Retourne (ab = NULL)
Fin*/
bool estVide (abin a) {
    return (a = NULL);
}
