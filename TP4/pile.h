#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include "fileAttente.h"

typedef struct e {
    FileAttente *file;
    e * suivant;
} element;

typedef struct {
    element * tete;
} Pile;

void initPile(Pile &pile);
void desinitPile(Pile &pile);
void empiler(Pile &pile, FileAttente *file);
void depiler(Pile &pile);
element * sommet(Pile pile);

FileAttente* copierFileAttente(const FileAttente source);

int longueurPile(Pile pile);

void undo(Pile &pile, FileAttente &file);
void enregistreEtat(Pile &pile, const FileAttente file);

#endif // PILE_H_INCLUDED
