#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct n {
    char etiquette;
    struct n* ag;
    struct n* ad;
} noeud;

<<<<<<< HEAD
noeud * abin;
=======
typedef noeud * abin;

void arbnouv (abin a);
void arbdetruit (abin a);
abin enracine(const char etiq, abin ag, abin ad)
>>>>>>> 88f0ae3f262c299f958440a9aed897e18c961344

#endif // ARBRE_H_INCLUDED
