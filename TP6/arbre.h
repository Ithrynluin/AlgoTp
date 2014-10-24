#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct n {
    char etiquette;
    struct n* ag;
    struct n* ad;
} noed;

noed * abin;

#endif // ARBRE_H_INCLUDED
