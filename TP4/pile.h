#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include "fileAttente.h"
typedef struct e {
    FileAttente file;
    struct e * suivant;
} element;

typedef struct {
    element * tete;
} Pile;

Pile initPile(Pile pile);

void empiler(Pile &pile, FileAttente *file);

element sommet(Pile pile);

void desinitPile(Pile &pile);

void depiler(Pile &pile);

FileAttente copier(FileAttente file);

#endif // PILE_H_INCLUDED
