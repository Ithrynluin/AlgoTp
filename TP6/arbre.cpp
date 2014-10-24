#include "arbre.h"


/*
Procédure qui initialise un arbre
Paramètre de sortie: arbre initialisé
Post-condition: le pointeur (abin) pointe sur rien
*/
void arbnouv (abin a) {
    a = new noeud;
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
abin gauche (abin a) {
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
abin droite (abin a) {
    if(a != NULL) {
        return (*a).ad;
    } else {
        return NULL;
    }
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

/*
Fonction booléenne permettant de savoir si un arbre est vide ou non
Paramètre d'entrée : arbre étudié
Paramètre de sortie : booléen indiquant si l'élément est null ou non
Pré-condition : l'arbre placé en paramètre doit être initialisé
*/
bool estVide (abin a) {
    return (a == NULL);
}

/*
Fonction renvoyant la racine d'un arbre
Paramètre d'entrée : arbre étudié
Paramètre de sortie : noeud racine de l'arbre placé en paramètre
Pré-condition : l'arbre doit être initialisé
*/
abin racine (abin a) {
    if(a != NULL) {
        return a;
    } else {
        return NULL;
    }
}

/*
Fonction permettant de connaitre la taille d'un arbre
Paramètre d'entrée : arbre initialisé
Paramètre de sortie : entier indiquant la taille de l'arbre
Pré-condition : l'arbre doit être initialisé
*/
int hauteur (abin a) {
    int g, d;

    if (a != NULL) {
        g = 0;
        d = 0;
        g = hauteur((*a).ag);
        d = hauteur((*a).ad);
        return (1+(g > d) ? g : d);
    } else {
        return 0;
    }
}

/*
Fonction permettant de renvoyer l'étiquette (=caractère) d'un noeud
Paramètre d'entrée : noeud choisi
Paramètre de sortie : étiquette(=caractère) du noeud
Pré-condition : le noeud doit être initialisé
*/
char charEtiquette (noeud * n) {
    if(n != NULL) {
        return (*n).etiquette;
    } else {
        return NULL;
    }
}

char * parcoursSuffixe(abin a){
    char * eg, *ed, *e;
    char et;
    if(a != NULL){
        et = charEtiquette(racine(a));
        eg = parcoursSuffixe((*a).ag);
        ed = parcoursSuffixe((*a).ad);
        e = new char[sizeof(eg) + sizeof(ed) + 1];
        e[0] = et;
        strcat(e, eg);
        strcat(e, ed);
    }else{
        e = new char;
        e[0] = '\0';
    }
    return e;
}

char * parcoursInfixe(abin a){
    char * eg, *ed, *r,*e;
    char et;
    if(a != NULL){
        eg = parcoursInfixe((*a).ag);
        et = charEtiquette(racine(a));
        ed = parcoursInfixe((*a).ad);
        e = new char[sizeof(eg) + sizeof(ed) + 1];
        r = new char[2];
        r[0] = et;
        r[1] = '\0';
        e = eg;
        strcat(e, r);
        strcat(e, ed);
    }else{
        e = new char;
        e[0] = '\0';
    }
    return e;
}

char * parcoursPrefixe(abin a){
    char * eg, *ed, *r,*e;
    char et;
    if(a != NULL){
        eg = parcoursPrefixe((*a).ag);
        ed = parcoursPrefixe((*a).ad);
        et = charEtiquette(racine(a));

        e = new char[sizeof(eg) + sizeof(ed) + 1];
        r = new char[2];
        r[0] = et;
        r[1] = '\0';
        e = eg;
        strcat(e, ed);
        strcat(e, r);
    }else{
        e = new char;
        e[0] = '\0';
    }
    return e;

}
