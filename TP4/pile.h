#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#inlcude "fileAttente.h"
typedef struct e {
    FileAttente file;
    struct e * suivant
} element;

typedef struct {
    element * tete;
} Pile;

#endif // PILE_H_INCLUDED
