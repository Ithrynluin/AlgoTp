//fileAttente.h
#ifndef FILEATTENTE_H_INCLUDED
#define FILEATTENTE_H_INCLUDED

/*
 Module de file d'attente.
 Permet de gérer une file d'attente:
    initialisation de la file
    ajout de personne en queue
    suppresion personne en tête
    consulter le tête de file, la longueur
*/

typedef struct pers {
    int numero;
    char * nom;
    struct pers * suivant;
} maillon;

typedef struct {
    maillon * tete;
    maillon * queu;
} FileAttente;

/*
Procédure qui initialise une file
Paramètre de sortie: file d'attente initialisé
Post-condition: la tete et la queue dont égale à NULL
*/
void initFileAttente(FileAttente * file);

/*
Procédure qui supprimer tous les élèment de la file
Paramètre d'entrée: File d'attente à vider
Paramètre de sortie: File d'attente vide
Pré-condition: La file doit être initialiser
Post-condition: La file est vide et initialisé
*/
void desinitFileAttente(FileAttente *file);

/*
Procédure permettant d'ajouter une personne en queue de file d'attente
Paramètres d'entrée : file d'attente à laquelle on doit ajouter un maillon
                        numero de la personne à ajouer
                        nom de la personne
Paramètres de sortie : file d'attente avec le nouveau maillon en queue
Pré-condition : la file d'attente doit être initialisé
Post-conditon : le nouveau maillon est en queue de file.
*/
void ajoutPers (FileAttente * f, const int num, char * nom);

/*
Procédure qui retire une personne en queue de file
Paramètre entrée: file d'attente initialiser
Paramètre sortie: file d'attente avec un élément retiré en tete
Pré-condition: la file ne doit pas etre vide
Post-condition: le deuxième maillon est maintenant en tete
                  Si file ne contient qu'un éléemnt, le file est initialisée
*/
void retireTete(FileAttente * file);

/*
Procédure permettant de consulter la personne en tete de file
Paramètre entrée : file d'attente initialisée
Paramètre sortie : affichage de la personne en tete
Pré-condition : la file doit être initialisée
Post-condition : retiurne le maillon de tete ou NULL si la file est vide
*/
maillon* consulterTete (FileAttente file);

/*
Fonction qui retourne la taille de la file
Paramètre d'entrée: la file d'attente
Retourne: la longueur de la file d'attente
Pré-condition: la file doit être initialisé
*/
int longueurFile(const FileAttente file);
#endif // FILEATTENTE_H_INCLUDED
