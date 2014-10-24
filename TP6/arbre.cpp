#include <iostream>
#include "arbre.h"
using namespace std;

void arbnouv (abin a) {
    a = NULL;
}

void arbdetruit (abin a) {
    if(a != NULL) {
        arbdetruit((*a).ag);
        arbdetruit((*a).ad);
        delete (a);
    }
}


