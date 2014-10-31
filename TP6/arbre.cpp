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
        return ((g > d) ? (g+1) : (d+1));
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

/*
Fonction permettant de parcourir un arbre en affichant en priorité les noeuds les plus hauts et les plus à gauche
Paramètre d'entrée : arbre initialisé
Retourne : liste de caractères affichant les étiquettes des noeuds selon l'ordre de priorisation
Pré-condition : l'arbre doit être initialisé
*/
Liste parcoursSuffixe(abin a){
    Liste listeEtiquette, listeDroite, listeGauche;
    char et;
    element * e;

    initListe(&listeEtiquette);
    e = new element;

    if(a != NULL){
        et = charEtiquette(racine(a));
        (*e).caractere = et;
        ajoueterElement(&listeEtiquette, e);
        listeGauche = parcoursSuffixe((*a).ag);
        listeDroite = parcoursSuffixe((*a).ad);
        concatenerListe(&listeEtiquette, &listeGauche);
        concatenerListe(&listeEtiquette, &listeDroite);
    }
    return listeEtiquette;
}

/*
Fonction permettant de parcourir un arbre en affichant en priorité les noeuds les plus à gauche et les plus bas
Paramètre d'entrée : arbre initialisé
Retourne : liste de caractères affichant les étiquettes des noeuds selon l'ordre de priorisation
Pré-condition : l'arbre doit être initialisé
*/
Liste parcoursInfixe(abin a){
    Liste listeEtiquette, listeGauche, listeDroite;
    char et;
    element *e;

    if(a != NULL){
        listeGauche = parcoursInfixe((*a).ag);
        et = charEtiquette(racine(a));
        listeDroite = parcoursInfixe((*a).ad);

        e = new element;
        (*e).caractere = et;

        listeEtiquette = listeGauche;
        ajoueterElement(&listeEtiquette, e);
        concatenerListe(&listeEtiquette, &listeDroite);
    }else{
        initListe(&listeEtiquette); // Si aucun noeud on retourne une liste vide
    }

    return listeEtiquette;
}

/*
Fonction permettant de parcourir un arbre en affichant en priorité les noeuds les plus bas et les plus à gauche
Paramètre d'entrée : arbre initialisé
Retourne : liste de caractères affichant les étiquettes des noeuds selon l'ordre de priorisation
Pré-condition : l'arbre doit être initialisé
*/
Liste parcoursPrefixe(abin a){
    Liste listeEtiquette, listeDroite, listeGauche;
    char et;
    element *e;

    if(a != NULL){
        listeGauche = parcoursPrefixe((*a).ag);
        listeDroite = parcoursPrefixe((*a).ad);
        et = charEtiquette(racine(a));

        listeEtiquette = listeGauche;
        concatenerListe(&listeEtiquette, &listeDroite);
        e = new element;
        (*e).caractere = et;
        ajoueterElement(&listeEtiquette, e);
    }else{
        initListe(&listeEtiquette);
    }
    return listeEtiquette;

}

char * parcoursLargeur(abin * file){
    abin * fileEnfant;
    char * listeNiveau;
    char * listeEnfant;
    char * listeEtiquette;
    abin a, enfant;
    int longueurFile = 50;

    int i = 0, j = 0;

    fileEnfant = new abin[(longueurFile)*2+1];
    listeNiveau = new char[longueurFile+1];


    if(file[0] != NULL){
        do{
            a = file[i];
            listeNiveau[i] = (*a).etiquette;
            cout << " ";

            enfant = gauche(a);
            if(enfant != NULL){
                fileEnfant[j]=enfant;
                j++;
            }
            enfant = droite(a);
            if(enfant != NULL){
                fileEnfant[j]=enfant;
                j++;
            }

            i++;
        }while(file[i] != NULL);
        listeNiveau[i] = '\0';
        fileEnfant[j] = NULL;
        listeEnfant = parcoursLargeur(fileEnfant);
        listeEtiquette = new char[100];
        listeEtiquette[0]='\0';
        strcat(listeEtiquette, listeNiveau);
        strcat(listeEtiquette, listeEnfant);
    }else{
        listeEtiquette[0] = '\0';
    }


    return listeEtiquette;
}
